#include "FrameInfo.h"

using namespace Common::Sprites;

FrameInfo::FrameInfo(std::string name, FrameType type, size_t texw, size_t texh) {
	this->name = name;
	this->type = type;
	this->texw = texw;
	this->texh = texh;
}