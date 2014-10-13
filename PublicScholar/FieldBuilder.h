#pragma once
#include "Bibliographic.h"
#include "Author.h"
#include "Doi.h"
#include "Issn.h"
#include "Journal.h"
#include "Month.h"
#include "Number.h"
#include "Pages.h"
#include "Title.h"
#include "Url.h"
#include "UrlDate.h"
#include "Volume.h"
#include "Year.h"
#include "KeyValuePair.h"
#include "Entry.h"

class FieldBuilder
{
public:
	FieldBuilder();
	~FieldBuilder();
	virtual Bibliographic buildField(const KeyValuePair& kvp); 
};

