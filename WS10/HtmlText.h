

#ifndef SDDS_HTMLTEXT_H__
#define SDDS_HTMLTEXT_H__
#include <ostream>
#include "Text.h"
namespace sdds {
    class HtmlText : public Text {
        char* m_title;
    public:
        HtmlText(const char* filename = nullptr, const char* title = nullptr);
        ~HtmlText();
        HtmlText(const HtmlText& text);
        HtmlText& operator=(const HtmlText& text);
        void write(std::ostream& ostr)const;
    };
}
#endif // !SDDS_HTMLTEXT_H__

