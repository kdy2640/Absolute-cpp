
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

namespace Doc
{

    class Document
    {
    public:
        Document() : text("") {}
        Document(string _text) : text(_text) {}
        Document(const Document& _D1) :text(_D1.getText()) {}

        string getText() const { return text; }
        void setText(const string _input) { text = _input; }

        Document& operator=(const Document& _D1) { text = _D1.getText(); return *this; }
    private:
        string text;
    };
    class Email : public Document
    {
    public:
        Email() : Document(), sender(""), recipient(""), title("") {}
        Email(const Document& _D1, string _send, string _recip, string _title) : Document(_D1), sender(_send), recipient(_recip), title(_title) {}
        Email(const Email& _E1) : Document(_E1), sender(_E1.getSender()), recipient(_E1.getRecipient()), title(_E1.getTitle()) {}

        string getSender() const { return sender; }
        string getRecipient()  const { return recipient; }
        string getTitle() const { return title; }
        void setSender(string _value) { sender = _value; }
        void Recipient(string _value) { recipient = _value; }
        void setTitle(string _value) { title = _value; }

        Email& operator=(const Email& _E1) { Document::operator=(_E1); sender = _E1.getSender(); recipient = _E1.getRecipient(); title = _E1.getTitle(); }

    private:
        string sender;
        string recipient;
        string title;
    };
    class File : public Document
    {
    public:
        File() : Document(), path("") {}
        File(const Document& _D1, string _path) : Document(_D1), path(path) {}
        File(const File& _F1) : Document(_F1), path(_F1.getPath()) {}

        string getPath() const { return path; }
        void setPath(string _value) { path = _value; }

        File& operator=(const File& _F1) { Document::operator=(_F1); path = _F1.getPath(); }

    private:
        string path;
    };

    bool ContainsKeyword(const Document& docObject, string keyword)
    {
        if (docObject.getText().find(keyword) != string::npos)
            return true;
        return false;
    }
}