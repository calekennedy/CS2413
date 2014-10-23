#include "FieldBuilder.h"


FieldBuilder::FieldBuilder()
{
}


FieldBuilder::~FieldBuilder()
{
}

Bibliographic FieldBuilder::buildField(const KeyValuePair& kvp)
{
	String key = kvp.getKey();
	Bibliographic field = Bibliographic(kvp);

	if (key == "author") {
		field = (Author)field;
		return field; 
	}

	else if (key == "doi") {
		field = Doi();
	}

	else if (key == "issn") {
		field = Issn();
	}

	else if (key == "journal") {
		field = Journal();
	}

	else if (key == "month") {
		field = Month();
	}

	else if (key == "number") {
		field = Number();
	}

	else if (key == "pages") {
		field = Pages();
	}

	else if (key == "title") {
		field = Title();
	}

	else if (key == "url") {
		field = Url();
	}

	else if (key == "urldate") {
		field = UrlDate();
	}

	else if (key == "volume") {
		field = Volume();
	}

	else if (key == "year") {
		field = Year();
	}

	else {
		field = Bibliographic();
		field.setKey(kvp.getKey());
	}
	field.setValue(kvp.getValue());
	return field;
}
