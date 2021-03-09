#include "Image.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <iostream>


Image::Image(const std::string &a_path)
{
  if((data = (Pixel*)stbi_load(a_path.c_str(), &width, &height, &channels, sizeof(Pixel))) != nullptr)
  {
    size = width * height * channels;
    back = (Pixel*)stbi_load(a_path.c_str(), &width, &height, &channels, sizeof(Pixel));
  }
}

Image::Image(int a_width, int a_height, int a_channels)
{
  data = new Pixel[a_width * a_height ]{};
  back = new Pixel[a_width * a_height ]{};

  if(data != nullptr)
  {
    width = a_width;
    height = a_height;
    size = a_width * a_height * a_channels;
    channels = a_channels;
    self_allocated = true;
  }
}

Image::Image(const Image& other)
{
  width = other.width;
  height = other.height;
  channels = other.channels;
  size = other.size;
  data = new Pixel[width * height];
  back = new Pixel[width * height];
  for(int i = 0; i < width* height; ++i)
  {
    data[i] = other.data[i];
    back[i] = other.back[i];
  }
  self_allocated = other.self_allocated;
}

int Image::Save(const std::string &a_path)
{
  auto extPos = a_path.find_last_of('.');
  if(a_path.substr(extPos, std::string::npos) == ".png" || a_path.substr(extPos, std::string::npos) == ".PNG")
  {
    stbi_write_png(a_path.c_str(), width, height, channels, data, width * channels);
  }
  else if(a_path.substr(extPos, std::string::npos) == ".jpg" || a_path.substr(extPos, std::string::npos) == ".JPG" ||
          a_path.substr(extPos, std::string::npos) == ".jpeg" || a_path.substr(extPos, std::string::npos) == ".JPEG")
  {
    stbi_write_jpg(a_path.c_str(), width, height, channels, data, 100);
  }
  else
  {
    std::cerr << "Unknown file extension: " << a_path.substr(extPos, std::string::npos) << "in file name" << a_path << "\n";
    return 1;
  }

  return 0;
}

Image::~Image()
{
  if(self_allocated)
  {
    delete [] data;
    data = nullptr;
  }
  else
  {
    stbi_image_free(data);
  }

  if(back)
  {
    delete [] back;
    back = nullptr;
  }
}

Pixel* Image::get_image()
{
  Pixel* image = new Pixel[width * height];
  for (int i = 0; i < width * height; i++)
  {
    image[i] = data[i];
  }
  return image;
}

void Image::fade(float dark)
{
  for (int i = 0; i < width * height; ++i)
  {
    data[i].r *= dark;
    data[i].g *= dark;
    data[i].b *= dark;
    data[i].a *= dark;
  }
}

void Image::back_in()
{
  for (int i = 0; i < width * height; ++i)
    data[i] = back[i];
}