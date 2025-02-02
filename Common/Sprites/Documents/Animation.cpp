#include "Animation.h"
#include "../../Logging/Logger.h"

using namespace Common;
using namespace Common::Logging;
using namespace Common::Logging::Logger;
using namespace Common::Sprites;
using namespace Common::Sprites::Documents;

Animation::Animation() : InfoBase() {
	this->animCells = std::vector<Cell*>();
}

Animation::Animation(std::string name) : InfoBase(name) {
	this->animCells = std::vector<Cell*>();
}

Animation::Animation(std::string name, std::vector<Cell*> cells) : InfoBase(name) {
	this->animCells = cells;
}

Animation* Animation::FromNode(rapidxml::xml_node<>* animNode) {
	rapidxml::xml_attribute<>* nextAttrib = animNode->first_attribute();

	/* Read the animation name */
	std::string animName;
	while (nextAttrib) {
		std::string attribName = nextAttrib->name();
		std::string attribValue = nextAttrib->value();

		if (attribName == "name") {
			animName = attribValue;
		}

		nextAttrib = nextAttrib->next_attribute();
	}
	if (animName.empty()) {
		Print(LogLevel::WARNING, "animName was empty for an Animation... An empty Animation will be returned");
		return new Animation();
	}

	/* Read the animation frames as cells */
	rapidxml::xml_node<>* nextNode = animNode->first_node();
	std::vector<Cell*> animCells;
	while (nextNode) {

		animCells.push_back(Cell::FromNode(nextNode));

		nextNode = nextNode->next_sibling();
	}

	return new Animation(animName, animCells);
}

const std::vector<Cell*>& Animation::GetCells()
{
	return this->animCells;
}

rapidxml::xml_node<>* Animation::ToXML(rapidxml::xml_document<>* document)
{
	rapidxml::xml_node<>* animNode = document->allocate_node(rapidxml::node_element, "Animation");
	rapidxml::xml_attribute<>* nameAttrib = document->allocate_attribute(
		"name",
		document->allocate_string(
			this->GetName().c_str()
		)
	);
	animNode->append_attribute(nameAttrib);
	for (Cell* c : this->GetCells()) {
		animNode->append_node(c->ToXML(document));
	}
	return animNode;
}
