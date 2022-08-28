#include "PngPhoto.h"
#include "../Logging/Logger.h"
#include "../Sprites/Images/BitmapImage.h"

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image.h>
#include <stb_image_write.h>

using namespace Common;
using namespace Common::Files;
using namespace Common::Files::Images;
using namespace Common::Logging;
using namespace Common::Logging::Logger;
using namespace Common::Sprites;
using namespace Common::Sprites::Images;
namespace fs = std::filesystem;

PngPhoto::PngPhoto() : Photo() {
	this->image = nullptr;
}

PngPhoto::PngPhoto(fs::path path) : Photo(path) {
	this->image = nullptr;
}

bool PngPhoto::Open(fs::path path) {
	return this->OpenRead(path);
}
bool PngPhoto::OpenRead(fs::path path) {
	Photo::OpenRead(path);

	int width = 0;
	int height = 0;
	int channels = 0;
	uint32_t* colorBytes = (uint32_t*)stbi_load(path.string().c_str(), &width, &height, &channels, 4);
	std::vector<uint32_t> imgData;
	imgData.assign(colorBytes, colorBytes + (width * height));

	CLImage* memImg = new CLImage(imgData, width, height);
	this->image = memImg;

	return true;
}
bool PngPhoto::OpenWrite(fs::path path) {
	return Photo::OpenWrite(path);;
}

Images::Image* PngPhoto::ReadImg() {
	return this->image;
}

void PngPhoto::WriteImg(Images::Image* image) {
	Photo::WriteImg(image);

	size_t width = image->GetWidth();
	size_t height = image->GetHeight();
	std::vector<uint32_t> colors = image->ColorBytes();

	stbi_write_png(this->GetPath().string().c_str(), width, height, 4, colors.data(), width * 4);
}