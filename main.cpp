#include "common.h"
#include "Image.h"
#include "Player.h"
#include "Map.h"
#include "Tile.h"
#include "Enemy.h"

#define GLFW_DLL
#include <GLFW/glfw3.h>

constexpr GLsizei WINDOW_WIDTH = 1024, WINDOW_HEIGHT = 512;

struct InputState
{
  bool keys[1024]{}; //массив состояний кнопок - нажата/не нажата
  GLfloat lastX = 400, lastY = 300; //исходное положение мыши
  bool firstMouse = true;
  bool captureMouse         = true;  // Мышка захвачена нашим приложением или нет?
  bool capturedMouseJustNow = false;
} static Input;


GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;


void OnKeyboardPressed(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	switch (key)
	{
	case GLFW_KEY_ESCAPE:
		if (action == GLFW_PRESS)
			glfwSetWindowShouldClose(window, GL_TRUE);
		break;
  case GLFW_KEY_1:
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    break;
  case GLFW_KEY_2:
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    break;
	default:
		if (action == GLFW_PRESS)
      Input.keys[key] = true;
		else if (action == GLFW_RELEASE)
      Input.keys[key] = false;
	}
}

void processPlayerMovement(Player &player, Level level)
{
  if (Input.keys[GLFW_KEY_W])
  {
    player.ProcessInput(MovementDir::UP, level);
  }
  else if (Input.keys[GLFW_KEY_S])
  {
    player.ProcessInput(MovementDir::DOWN, level);
  }
  if (Input.keys[GLFW_KEY_A])
  {
    player.ProcessInput(MovementDir::LEFT, level);
  }
  else if (Input.keys[GLFW_KEY_D])
  {
    player.ProcessInput(MovementDir::RIGHT, level);
  }
}

void OnMouseButtonClicked(GLFWwindow* window, int button, int action, int mods)
{
  if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
    Input.captureMouse = !Input.captureMouse;

  if (Input.captureMouse)
  {
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    Input.capturedMouseJustNow = true;
  }
  else
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

}

void OnMouseMove(GLFWwindow* window, double xpos, double ypos)
{
  if (Input.firstMouse)
  {
    Input.lastX = float(xpos);
    Input.lastY = float(ypos);
    Input.firstMouse = false;
  }

  GLfloat xoffset = float(xpos) - Input.lastX;
  GLfloat yoffset = Input.lastY - float(ypos);

  Input.lastX = float(xpos);
  Input.lastY = float(ypos);
}


void OnMouseScroll(GLFWwindow* window, double xoffset, double yoffset)
{
  // ...
}


int initGL()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize OpenGL context" << std::endl;
		return -1;
	}

	std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;

  std::cout << "Controls: "<< std::endl;
  std::cout << "press right mouse button to capture/release mouse cursor  "<< std::endl;
  std::cout << "W, A, S, D - movement  "<< std::endl;
  std::cout << "press ESC to exit" << std::endl;

	return 0;
}


int main(int argc, char** argv)
{
	if(!glfwInit())
    return -1;

//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

  GLFWwindow*  window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "normal game", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	
	glfwMakeContextCurrent(window); 

	glfwSetKeyCallback        (window, OnKeyboardPressed);  
	glfwSetCursorPosCallback  (window, OnMouseMove); 
  glfwSetMouseButtonCallback(window, OnMouseButtonClicked);
	glfwSetScrollCallback     (window, OnMouseScroll);

	if(initGL() != 0) 
		return -1;
	
  //Reset any OpenGL errors which could be present for some reason
	GLenum gl_error = glGetError();
	while (gl_error != GL_NO_ERROR)
		gl_error = glGetError();

	Point starting_pos{.x = WINDOW_WIDTH / 2, .y = WINDOW_HEIGHT / 2};
	Player player{starting_pos};


  Map map("./resources/Labirint"); 
  Tile tile;

	Image screenBuffer(WINDOW_WIDTH, WINDOW_HEIGHT, 4);
  Image end("./resources/endgame.jpg");
  Image finish("./resources/victory2.jpg");

  Level current_level = map.get_current();

  tile.load_back(current_level, screenBuffer);

  Point starting_pos1{.x = 448, .y = 352};
  Point starting_pos2{.x = 768, .y = 128};

  switch(current_level.type)
  {
    case 'A':
      starting_pos1 = {.x = 448, .y = 352};
      starting_pos2 = {.x = 768, .y = 128};
      break;
    case 'B':
      starting_pos1 = {.x = 608, .y = 416};
      starting_pos2 = {.x = 768, .y = 128};
      break;
    case 'C':
      starting_pos1 = {.x = 160, .y = 480};
      starting_pos2 = {.x = 800, .y = 224};
      break;
    case 'D':
      starting_pos1 = {.x = 608, .y = 160};
      starting_pos2 = {.x = 288, .y = 384};
      break;
  }

  Enemy enemy1(starting_pos1);
  Enemy enemy2(starting_pos2);

  glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);  GL_CHECK_ERRORS;
  glClearColor(100.2f, 100.3f, 0.3f, 100.0f); GL_CHECK_ERRORS;
  

  GLfloat change_time = 0.0f;
  int count = 2;
  //game loop
	while (!glfwWindowShouldClose(window))
	{

		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
    change_time += deltaTime;
		lastFrame = currentFrame;
    glfwPollEvents();


    processPlayerMovement(player, current_level);
    enemy1.move(current_level);
    enemy2.move(current_level);

    if (Input.keys[GLFW_KEY_W])
    {
      if (player.direction != 'w')
      {
        player.direction = 'w';
        tile.player_up();
      }
      if (player.up / 40 > 0)
        tile.player_pic(1);
      player.up %= 40;
    }
    else if (Input.keys[GLFW_KEY_S])
    {
      if (player.direction != 's')
      {
        player.direction = 's';
        tile.player_down();
      }
      if (player.down / 40 > 0)
        tile.player_pic(3);
      player.down %= 40;
    }
    if (Input.keys[GLFW_KEY_A])
    {
      if (player.direction != 'a')
      {
        player.direction = 'a';
        tile.player_pic(4);
      }
      if (player.left / 40 > 0)
        tile.player_pic(4);
      player.left %= 40;
    }
    else if (Input.keys[GLFW_KEY_D])
    {
      if (player.direction != 'd')
      {
        player.direction = 'd';
        tile.player_pic(2);
      }
      if (player.right / 40 > 0)
        tile.player_pic(2);
      player.right %= 40;
    }

    switch (enemy1.state)
    {
      case 5:
      case 1:
        if (enemy1.direction != 'w')
        {
          enemy1.direction = 'w';
          tile.enemy_pic(1, 1);
        }
        else if  (enemy1.anima / 40 > 0)
        {
          tile.enemy_pic(1, 1);
          enemy1.anima %= 40;
        }
        break;
      case 2:
      case 4:
        if (enemy1.direction != 'a')
        {
          enemy1.direction = 'a';
          tile.enemy_pic(1, 4);
        }
        else if (enemy1.anima / 40 > 0)
        {
          tile.enemy_pic(1, 4);
          enemy1.anima %= 40;
        }
        break;
      case 3:
      case 7:
        if (enemy1.direction != 's')
        {
          enemy1.direction = 's';
          tile.enemy_pic(1, 3);
        }
        else if (enemy1.anima / 40 > 0)
        {
          tile.enemy_pic(1, 3);
          enemy1.anima %= 40;
        }
        break;
      case 6:
      case 8:
        if (enemy1.direction != 'd')
        {
          enemy1.direction = 'd';
          tile.enemy_pic(1, 2);
        }
        else if (enemy1.anima / 40 > 0)
        {
          tile.enemy_pic(1, 2);
          enemy1.anima %= 40;
        }
        break;
    }

    switch (enemy2.state)
    {
      case 5:
      case 1:
        if (enemy2.direction != 'w')
        {
          enemy2.direction = 'w';
          tile.enemy_pic(2, 1);
        } 
        else if (enemy2.anima / 40 > 0)
        {
          tile.enemy_pic(2, 1);
          enemy2.anima %= 40;
        }
        break;
      case 2:
      case 4:
        if (enemy2.direction != 'a')
        {
          enemy2.direction = 'a';
          tile.enemy_pic(2, 4);
        } 
        else if (enemy2.anima / 40 > 0)
        {
          tile.enemy_pic(2, 4);
          enemy2.anima %= 40;
        }
        break;
      case 3:
      case 7:
        if (enemy2.direction != 's')
        {
          enemy2.direction = 's';
          tile.enemy_pic(2, 3);
        } 
        else if (enemy2.anima / 40 > 0)
        {
          tile.enemy_pic(2, 3);
          enemy2.anima %= 40;
        }
        break;
      case 6:
      case 8:
        if (enemy2.direction != 'd')
        {
          enemy2.direction = 'd';
          tile.enemy_pic(2, 2);
        } 
        else if (enemy2.anima / 40 > 0)
        {
          tile.enemy_pic(2, 2);
          enemy2.anima %= 40;
        }
        break;
    }

    if (change_time > 0.5f)
    {
      if (count == 4)
      {
        count = 0;
      }
      count++;
      tile.change_time();
      tile.load_back(current_level, screenBuffer);
      change_time = 0;
    }

    tile.Draw_player(player.get_coords(), player.get_old_coords(), screenBuffer);
    tile.Draw_enemy1(enemy1.coords, enemy1.old_coords, screenBuffer);
    tile.Draw_enemy2(enemy2.coords, enemy2.old_coords, screenBuffer);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); GL_CHECK_ERRORS;
    glDrawPixels (WINDOW_WIDTH, WINDOW_HEIGHT, GL_RGBA, GL_UNSIGNED_BYTE, screenBuffer.Data()); GL_CHECK_ERRORS;

    if ((current_level.tile_type(player.coords.x, player.coords.y + tileSize - 1) == ' ') || (current_level.tile_type(player.coords.x + tileSize - 1, player.coords.y + tileSize - 1) == ' ') ||
    (current_level.tile_type(player.coords.x, player.coords.y) == ' ') || (current_level.tile_type(player.coords.x + tileSize - 1, player.coords.y) == ' '))
      player.is_dead = 1;
    else if ((current_level.tile_type(player.coords.x, player.coords.y + tileSize - 1) == 'T') || (current_level.tile_type(player.coords.x + tileSize - 1, player.coords.y + tileSize - 1) == 'T') ||
    (current_level.tile_type(player.coords.x, player.coords.y) == 'T') || (current_level.tile_type(player.coords.x + tileSize - 1, player.coords.y) == 'T'))
      player.is_dead = 2;

    if ((player.coords.x - enemy1.coords.x < tileSize) && (player.coords.x - enemy1.coords.x > -tileSize) && (player.coords.y - enemy1.coords.y < tileSize) && (player.coords.y - enemy1.coords.y > -tileSize))
      player.is_dead = 1;
    else if ((player.coords.x - enemy2.coords.x < tileSize) && (player.coords.x - enemy2.coords.x > -tileSize) && (player.coords.y - enemy2.coords.y < tileSize) && (player.coords.y - enemy2.coords.y > -tileSize))
      player.is_dead = 1;

    if (player.is_dead != 0)
    {
        if((player.is_dead == 1) || ((count == 4) && (player.is_dead == 2)))
        {
        while (!glfwWindowShouldClose(window))
        {
          GLfloat currentFrame1 = glfwGetTime();
		      deltaTime = currentFrame1 - lastFrame;
		      lastFrame = currentFrame1;
          glfwPollEvents();
          glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); GL_CHECK_ERRORS;
          glDrawPixels (WINDOW_WIDTH, WINDOW_HEIGHT, GL_RGBA, GL_UNSIGNED_BYTE, end.Data()); GL_CHECK_ERRORS;
          glfwSwapBuffers(window);
        }
        break;
        }
        else
          player.is_dead = false;
    }

    if (player.finish() == true)
    {
        while (!glfwWindowShouldClose(window))
        {
          GLfloat currentFrame1 = glfwGetTime();
		      deltaTime = currentFrame1 - lastFrame;
		      lastFrame = currentFrame1;
          glfwPollEvents();
          glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); GL_CHECK_ERRORS;
          glDrawPixels (WINDOW_WIDTH, WINDOW_HEIGHT, GL_RGBA, GL_UNSIGNED_BYTE, finish.Data()); GL_CHECK_ERRORS;
          glfwSwapBuffers(window);
        }
        break;
    }

    if (player.exit != 0)
    {
      for(int i = 0; i < 3; ++i)
      {
        tile.open_doors();
        tile.load_back(current_level, screenBuffer);
        tile.Draw_player(player.get_coords(), player.get_old_coords(), screenBuffer);
        tile.Draw_enemy1(enemy1.coords, enemy1.old_coords, screenBuffer);
        tile.Draw_enemy2(enemy2.coords, enemy2.old_coords, screenBuffer);

        float currentFrame1 = glfwGetTime();
        float lastFrame = currentFrame1;
        float deltaTime = currentFrame1 - lastFrame;

        while (deltaTime < 0.2f)
        {
          glDrawPixels (WINDOW_WIDTH, WINDOW_HEIGHT, GL_RGBA, GL_UNSIGNED_BYTE, screenBuffer.Data()); GL_CHECK_ERRORS;
          glfwSwapBuffers(window);
          currentFrame1 = glfwGetTime();
          deltaTime = currentFrame1 - lastFrame;
        }
      }
      float fading = 1.5f;

      float currentFrame1 = glfwGetTime();
      float lastFrame = currentFrame1;
      float deltaTime = currentFrame1 - lastFrame;
      while(deltaTime < fading)
      {
        tile.Draw_player(player.get_coords(), player.get_old_coords(), screenBuffer);
        screenBuffer.fade(1.0f - (deltaTime / fading));
        glDrawPixels (WINDOW_WIDTH, WINDOW_HEIGHT, GL_RGBA, GL_UNSIGNED_BYTE, screenBuffer.Data()); GL_CHECK_ERRORS;
        glfwSwapBuffers(window);
        screenBuffer.back_in();
        currentFrame1 = glfwGetTime();
        deltaTime = currentFrame1 - lastFrame;
      }
      
      map.set_current(current_level.get_next(player.exit));
      current_level = map.get_current();
      tile.load_back(current_level, screenBuffer);
      switch (player.exit)
      {
        case 1:
          tile.player_pic(1);
          starting_pos = {.x = WINDOW_WIDTH / 2, .y = tileSize};
          break;
        case 2:
          tile.player_pic(2);
          starting_pos = {.x = tileSize, .y = WINDOW_HEIGHT / 2};
          break;
        case 3:
          tile.player_pic(3);
          starting_pos = {.x = WINDOW_WIDTH / 2, .y = WINDOW_HEIGHT - 2 * tileSize};
          break;
        case 4:
          tile.player_pic(4);
          starting_pos = {.x = WINDOW_WIDTH - 2 * tileSize, .y = WINDOW_HEIGHT / 2};
          break;
        default:
          break;
      }

    switch(current_level.type)
    {
    case 'A':
      starting_pos1 = {.x = 448, .y = 352};
      starting_pos2 = {.x = 768, .y = 128};
      break;
    case 'B':
      starting_pos1 = {.x = 608, .y = 416};
      starting_pos2 = {.x = 768, .y = 128};
      break;
    case 'C':
      starting_pos1 = {.x = 160, .y = 480};
      starting_pos2 = {.x = 800, .y = 224};
      break;
    case 'D':
      starting_pos1 = {.x = 608, .y = 160};
      starting_pos2 = {.x = 288, .y = 384};
      break;
    }

      enemy1.set_pos(starting_pos1);
      enemy2.set_pos(starting_pos2);

      player.set_pos(starting_pos);
      player.exit = 0;

      currentFrame1 = glfwGetTime();
      lastFrame = currentFrame1;
      deltaTime = currentFrame1 - lastFrame;
      while(deltaTime < fading)
      {
        tile.Draw_player(player.get_coords(), player.get_old_coords(), screenBuffer);
        screenBuffer.fade((deltaTime / fading));
        glDrawPixels (WINDOW_WIDTH, WINDOW_HEIGHT, GL_RGBA, GL_UNSIGNED_BYTE, screenBuffer.Data()); GL_CHECK_ERRORS;
        glfwSwapBuffers(window);
        screenBuffer.back_in();
        currentFrame1 = glfwGetTime();
        deltaTime = currentFrame1 - lastFrame;
      }
      tile.open_doors();
      tile.load_back(current_level, screenBuffer);
      glDrawPixels (WINDOW_WIDTH, WINDOW_HEIGHT, GL_RGBA, GL_UNSIGNED_BYTE, screenBuffer.Data()); GL_CHECK_ERRORS;
      glfwSwapBuffers(window);

    }

    glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}
