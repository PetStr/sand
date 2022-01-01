
#include "variadic.hh"
#include <cstdint>
#include <iostream>

tab::tab(std::ostream& out, const std::string& tab_name)
    : output(out)
    , frozen(true)
    , got_hidden(false)
    , got_width(false)
    , got_index(false)
    , got_span(false)
    , hidden(false)
    , index(0)
    , span(0)
{
    output << "Tab name (frozen)" << tab_name << '\n'; 
}

tab::tab(std::ostream& out, const std::string& tab_name, bool froz)
    : output(out)
    , frozen(froz)
    , got_hidden(false)
    , got_width(false)
    , got_index(false)
    , got_span(false)
    , hidden(false)
    , index(0)
    , span(0)
{
    output << "Tab name " << tab_name << '\n'; 
}

tab::~tab()
{
    if (frozen)
        output << "end (frozen)\n";
    else
        output << "end\n";
}

void tab::handle(Hidden value)
{
    hidden = value();
    got_hidden = true;
}

void tab::handle(const Width& value)
{
    width = value();
    got_width = true;
}

void tab::handle(Index value)
{
    index = value();
    got_index = true;
}

void tab::handle(Span value)
{
    span = value();
    got_span = true;
}


void tab::Column()
{
    output << "<Column ";

    if (got_index)
        {
            output << "ss:Index=\"" << index << "\" ";
        }
    if (got_hidden && hidden)
        {
            output << R"(ss:Hidden="1" )";
        }

    output << R"(ss:AutoFitWidth="0" )";

    if (got_width)
        {
            output << R"(ss:Width=")" << width << "\"";
        }

    if (got_span)
        {
            output << R"( ss:Span=")" << span << "\"";
        }
    output << R"(/>)" << '\n';

    got_span = false;
    got_width = false;
    got_index = false;
    got_hidden = false;
}

