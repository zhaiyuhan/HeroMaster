#include "SearchLineEdit.h"

SearchLineEdit::SearchLineEdit(QWidget *parent) : QLineEdit(parent)
{
    setPlaceholderText(QStringLiteral("Search ..."));
    searchAction = new QAction(this);
    searchAction->setIcon(QIcon(":/Basic/search.png"));
    addAction(searchAction, QLineEdit::TrailingPosition);
}
