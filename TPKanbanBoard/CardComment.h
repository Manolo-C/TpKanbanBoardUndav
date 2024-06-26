#define CARDCOMMENT_H_

#include <string>
using std::string;

namespace KanbandBoardCardComment {
	struct CardComment;

	/*
	 * Precondici�n: Ninguna.
	 * Postcondici�n: Devuelve una instancia valida de CardComment propietaria del autor @author con
	 * el texto @text, la cual ademas guarda la fecha y hora de creaci�n del comentario.
	 */
	CardComment* CreateCardComment(string author, string text);

	/*
	 * Precondici�n: @comment fue creada con la primitiva KanbandBoardCardComment::CreateCardComment
	 * Postcondici�n: Devuelve el autor del comentario de @comment
	 */
	string GetAuthor(CardComment* comment);

	/*
	 * Precondici�n: @comment fue creada con la primitiva KanbandBoardCardComment::CreateCardComment
	 * Postcondici�n: Si el autor de @comment es @uthor entonces cambia el texto de @comment por @text.
	 * Caso contrario no realiza ninguna acci�n
	 */
	void SetText(CardComment* comment, string author, string text);

	/*
	 * Precondici�n: @comment fue creada con la primitiva KanbandBoardCardComment::CreateCardComment
	 * Postcondici�n: Obtiene el texto de @comment.
	 */
	string GetText(CardComment* comment);

	/*
	 * Precondici�n: @comment fue creada con la primitiva KanbandBoardCardComment::CreateCardComment
	 * Postcondici�n: Obtiene el responsable asignado de @card en formato [dd/mm/aaaa HH:mm:ss]
	 */
	string GetCreationDate(CardComment* comment);

	/*
	 * Precondici�n: @comment fue creada con la primitiva KanbandBoardCardComment::CreateCardComment
	 * Postcondici�n: Libera todos los recursos asociados de @comment
	 */
	void DestroyComment(CardComment* comment);
}