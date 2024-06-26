#include <string>
#include <time.h>
#include "CardComment.h"

using namespace std;
using namespace KanbandBoardCardComment;

struct KanbandBoardCardComment::CardComment
{
    string author;
    string text;
    string creationDate;
};

CardComment* KanbandBoardCardComment::CreateCardComment(string author, string text)
{
    time_t localHour;
    time(&localHour);
    CardComment* nuevaCardComment = new CardComment;
    nuevaCardComment->author = author;
    nuevaCardComment->text = text;
    nuevaCardComment->creationDate = "FECHA Y HORA OMG";//ctime(&localHour);
    return nuevaCardComment;
}

string KanbandBoardCardComment::GetAuthor(CardComment* comment)
{
    return comment->author;
}

void KanbandBoardCardComment::DestroyComment(CardComment* comment)
{
    // TODO: ¿Aplicar lo mismo que en DestroyCard?
    delete comment;
}

void KanbandBoardCardComment::SetText(CardComment* comment, string author, string text) {
    if (comment->author == author)
    {
        comment->text = text;
    }
}

string KanbandBoardCardComment::GetText(CardComment* comment) {
    return comment->text;
}

string KanbandBoardCardComment::GetCreationDate(CardComment* comment) {
    return comment->creationDate;
}