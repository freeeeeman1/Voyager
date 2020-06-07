#ifndef TBBUF_H
#define TBBUF_H
#include <QTextBrowser>

class TBBuf : public std::streambuf
{
private:
    QTextBrowser *tbOut;

protected:
    virtual int_type overflow(int_type c) {
        if (c != traits_type::eof() && tbOut) {
            tbOut->moveCursor(QTextCursor::End);
            tbOut->insertPlainText((QChar(c)));
            return c;
        }
        return traits_type::eof();
    }

    // By default, superclass::xsputn call overflow method,
    // but for performance reason, here we override xsputn
    virtual std::streamsize xsputn(const char * str, std::streamsize n) {
        if (tbOut && n > 0) {
            tbOut->moveCursor(QTextCursor::End);
            tbOut->insertPlainText(QString::fromLatin1(str, n));
        }

        return n;
    }

public:
    TBBuf(QTextBrowser *tb) : tbOut(tb) {}
};

#endif // TBBUF_H
