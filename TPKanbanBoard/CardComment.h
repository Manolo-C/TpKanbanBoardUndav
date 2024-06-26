#define CARDCOMMENT_H_

#include <string>
using std::string;

namespace KanbandBoardCardComment {
	struct CardComment;

	/*
	 * Precondición: Ninguna.
	 * Postcondición: Devuelve una instancia valida de CardComment propietaria del autor @author con
	 * el texto @text, la cual ademas guarda la fecha y hora de creación del comentario.
	 */
	CardComment* CreateCardComment(string author, string text);

	/*
	 * Precondición: @comment fue creada con la primitiva KanbandBoardCardComment::CreateCardComment
	 * Postcondición: Devuelve el autor del comentario de @comment
	 */
	string GetAuthor(CardComment* comment);

	/*
	 * Precondición: @comment fue creada con la primitiva KanbandBoardCardComment::CreateCardComment
	 * Postcondición: Si el autor de @comment es @uthor entonces cambia el texto de @comment por @text.
	 * Caso contrario no realiza ninguna acción
	 */
	void SetText(CardComment* comment, string author, string text);

	/*
	 * Precondición: @comment fue creada con la primitiva KanbandBoardCardComment::CreateCardComment
	 * Postcondición: Obtiene el texto de @comment.
	 */
	string GetText(CardComment* comment);

	/*
	 * Precondición: @comment fue creada con la primitiva KanbandBoardCardComment::CreateCardComment
	 * Postcondición: Obtiene el responsable asignado de @card en formato [dd/mm/aaaa HH:mm:ss]
	 */
	string GetCreationDate(CardComment* comment);

	/*
	 * Precondición: @comment fue creada con la primitiva KanbandBoardCardComment::CreateCardComment
	 * Postcondición: Libera todos los recursos asociados de @comment
	 */
	void DestroyComment(CardComment* comment);
}