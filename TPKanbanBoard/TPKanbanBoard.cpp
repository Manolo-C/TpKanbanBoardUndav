#include <iostream>
#include <string>
#include "Card.h"
#include "CardComment.h"
#include "Column.h"
#include "State.h"

using namespace std;
using KanbanBoardCard::Card;
using KanbanBoardColumn::Column;

const string idTarjeta1 = "Algo-01";
const string idTarjeta2 = "Algo-02";
const string idTarjeta3 = "Algo-03";
const string idTarjeta4 = "Algo-04";
const string idTarjeta5 = "Algo-05";

const int CantidadColumnas = 3;
struct TableroKanban {
	Column* columnas[CantidadColumnas];
};

TableroKanban* CrearTableroKanban();
void CargarBacklogTareas(Column* backlog);
void PriorizarBacklogTareas(Column* backlog);
Card* CrearTareaConfiguracionAmbienteDesarrollo(string id);
Card* CrearTareaImplementacionCard(string id);
Card* CrearTareaAgregarComentariosACard(string id);
Card* CrearTareaAgregarEstadosCard(string id);
Card* CrearTareaAgregarColumna(string id);
void MoverTareasSegundaEntregaAColumnaEnProgreso(Column* backlog, Column* enProgreso);
void MoverTareasPrimerEntregaAColumnaTerminado(Column* backlog, Column* terminado);
void MostrarColumna(Column* columna);
void  MostrarCard(Card* card);
void  MostrarComment(CardComment* comment);

int main() {
	TableroKanban* tableroKanban = CrearTableroKanban();

	cout << "Cargando backlog de tareas..." << endl;
	CargarBacklogTareas(tableroKanban->columnas[0]);
	cout << "Backlog cargado." << endl << endl;
	MostrarColumna(tableroKanban->columnas[0]);

	cout << endl << "Priorizando backlog de tareas..." << endl;
	PriorizarBacklogTareas(tableroKanban->columnas[0]);
	cout << "Backlog priorizado." << endl << endl;

	cout << endl << "Moviendo tareas del backlog..." << endl;
	MoverTareasPrimerEntregaAColumnaTerminado(tableroKanban->columnas[0], tableroKanban->columnas[2]);
	MoverTareasSegundaEntregaAColumnaEnProgreso(tableroKanban->columnas[0], tableroKanban->columnas[1]);
	cout << "Tareas del backlog movidas." << endl << endl;
	for (int i = 0; i < 3; ++i)
	{
		MostrarColumna(tableroKanban->columnas[i]);
		cout << endl;
		KanbanBoardColumn::DestroyColumn(tableroKanban->columnas[i]);
	}

	delete tableroKanban;
}

TableroKanban* CrearTableroKanban()
{
	TableroKanban* tablero = new TableroKanban;
	tablero->columnas[0] = KanbanBoardColumn::CreateColumn("Backlog", KanbanBoardState::CreateState("ToDo"));
	tablero->columnas[1] = KanbanBoardColumn::CreateColumn("En progreso", KanbanBoardState::CreateState("InProgress"));
	tablero->columnas[2] = KanbanBoardColumn::CreateColumn("Terminado", KanbanBoardState::CreateState("Done"));

	return tablero;
}

void CargarBacklogTareas(Column* backlog)
{
	KanbanBoardColumn::AddCard(backlog, CrearTareaAgregarColumna(idTarjeta5));
	KanbanBoardColumn::AddCard(backlog, CrearTareaAgregarEstadosCard(idTarjeta4));
	KanbanBoardColumn::AddCard(backlog, CrearTareaAgregarComentariosACard(idTarjeta3));
	KanbanBoardColumn::AddCard(backlog, CrearTareaImplementacionCard(idTarjeta2));
	KanbanBoardColumn::AddCard(backlog, CrearTareaConfiguracionAmbienteDesarrollo(idTarjeta1));
}

void PriorizarBacklogTareas(Column* backlog)
{
	/*
	 * Quiero que quede en el backlog en orden (ver el orden actual en funcion CargarBacklogTareas):
	 * idTarjeta1
	 * idTarjeta2
	 * idTarjeta3
	 * idTarjeta4
	 * idTarjeta5
	 */
	KanbanBoardColumn::UpCardPriority(backlog, idTarjeta3);
	MostrarColumna(backlog);
	KanbanBoardColumn::UpCardPriority(backlog, idTarjeta3);
	MostrarColumna(backlog);
	KanbanBoardColumn::UpCardToTopPriority(backlog, idTarjeta2);
	MostrarColumna(backlog);
	KanbanBoardColumn::UpCardToTopPriority(backlog, idTarjeta1);
	MostrarColumna(backlog);
	KanbanBoardColumn::UpCardPriority(backlog, idTarjeta4);
	MostrarColumna(backlog);
}

Card* CrearTareaConfiguracionAmbienteDesarrollo(string id)
{
	Card* card = KanbanBoardCard::CreateCard(id, "Configurar el Ambiente de desarrollo.");
	KanbanBoardCard::SetDescription(card, "El proyecto tiene que estar configurado con todos los archivos fuentes (y compilando todo el tiempo!). Esto es necesario");
	KanbanBoardCard::AddComment(card, KanbandBoardCardComment::CreateCardComment("Estudiante", "�Que significa \"Ambiente de desarrollo\""));
	KanbanBoardCard::AddComment(card, KanbandBoardCardComment::CreateCardComment("Profe", "Ambiente o entorno de desarrollo se refiere a la pc con todo el software necesario y configurado correctamente para programar. En su caso se refiere a sus PC's con el IDE instalado y el proyecto configurado (compilando correctamente). Idealmente el ambiente de desarrollo tiene que ser lo m�s parecido al ambiente de producci�n (donde se instala el software que se desarrolla), esto �ltimo en su caso no tiene relevancia."));
	return card;
}

Card* CrearTareaImplementacionCard(string id)
{
	Card* card = KanbanBoardCard::CreateCard(id, "Implementar el TDA Card.");
	KanbanBoardCard::SetDescription(card, "Como un miembro del equipo de trabajo de un proyecto quiero poder crear una Card para poder definir el alcance de una funcionalidad o tarea valiosa");
	KanbanBoardCard::AddComment(card, KanbandBoardCardComment::CreateCardComment("Estudiante", "�Qu�?"));
	KanbanBoardCard::AddComment(card, KanbandBoardCardComment::CreateCardComment("Profe", "La descripci�n de esta card esta en un formato particular,  conocido como Story Card. Las stories card sirven en principio para iniciar una conversaci�n, y poder definir los requerimientos de una funcionalidad. Si prestan atenci�n en formato es el siguiente: Como X quiero poder hacer Y para Z. X representa un interesado en una funcioanalidad (rol de un usuario del sistema). Y representa una funcionalidad. Z representa el valor que agrega al negocio esa funcionalidad, es decir el porque es importante esa funcionalidad"));
	KanbanBoardCard::AddComment(card, KanbandBoardCardComment::CreateCardComment("Estudiante", "�A qu� se refiere con \"iniciar una conversaci�n\"?"));
	KanbanBoardCard::AddComment(card, KanbandBoardCardComment::CreateCardComment("Profe", "Por ejemplo, luego de que esta tarjeta fue escrita, el equipo de desarrollo podr�a comenzar una conversaci�n sobre el alcance de esta Story Card y decidir: Creemos un TDA Card, declaremos su interfaz y validemosla con el product owner, luego la implementamos."));
	KanbanBoardCard::AddComment(card, KanbandBoardCardComment::CreateCardComment("Estudiante", "�Qu� es un product owner?"));
	KanbanBoardCard::AddComment(card, KanbandBoardCardComment::CreateCardComment("Profe", "Product owner es un rol que define a una persona muy importante en un proyecto: La persona que m�s sabe del producto que se desarrolla desde la perspectiva del usuario, es el representante del usuario dentro del equipo y es el que puede definir el alcance y las prioridades de las Story Card"));
	return card;
}

Card* CrearTareaAgregarComentariosACard(string id)
{
	Card* card = KanbanBoardCard::CreateCard(id, "Implementar el TDA Card Comment.");
	KanbanBoardCard::SetDescription(card, "Como un miembro del equipo de trabajo de un proyecto quiero poder agregar un comentario a una Card para agregar inforamcion o realizar preguntas a alg�n miembro del equipo y que esto quede como parte de la historia de la Card");
	return card;
}

Card* CrearTareaAgregarEstadosCard(string id)
{
	Card* card = KanbanBoardCard::CreateCard(id, "Implementar el TDA State.");
	return card;
}

Card* CrearTareaAgregarColumna(string id)
{
	Card* card = KanbanBoardCard::CreateCard(id, "Implementar el TDA Column.");
	return card;
}

void  MostrarCard(Card* card)
{
	cout << KanbanBoardCard::GetId(card) << " " << KanbanBoardCard::GetName(card) << endl;
	cout << KanbanBoardCard::GetDescription(card) << endl;
	for (unsigned int i = 0; i < KanbanBoardCard::GetCommentCount(card); ++i)
	{
		MostrarComment(KanbanBoardCard::GetComment(card, i));
	}
	cout << endl;
}

void  MostrarComment(CardComment* comment)
{
	cout << "\t" << KanbandBoardCardComment::GetAuthor(comment) << " (" << KanbandBoardCardComment::GetCreationDate(comment) << ") : " << KanbandBoardCardComment::GetText(comment) << endl;
}

void MoverTareasSegundaEntregaAColumnaEnProgreso(Column* backlog, Column* enProgreso)
{
	Card* tareasPrimerEntrega[2];
	tareasPrimerEntrega[0] = KanbanBoardColumn::GetCard(backlog, idTarjeta4);
	tareasPrimerEntrega[1] = KanbanBoardColumn::GetCard(backlog, idTarjeta5);
	cout << "Tarjetas segunda entrega obtenidas" << endl;
	for (int i = 0; i < 2; ++i)
	{
		KanbanBoardColumn::RemoveCard(backlog, tareasPrimerEntrega[i]);
		KanbanBoardColumn::AddCard(enProgreso, tareasPrimerEntrega[i]);
	}
	cout << "Tarjetas segunda entrega movidas" << endl;
}

void MoverTareasPrimerEntregaAColumnaTerminado(Column* backlog, Column* terminado)
{
	Card* tareasPrimerEntrega[3];
	tareasPrimerEntrega[2] = KanbanBoardColumn::GetCard(backlog, idTarjeta3);
	tareasPrimerEntrega[1] = KanbanBoardColumn::GetCard(backlog, idTarjeta2);
	tareasPrimerEntrega[0] = KanbanBoardColumn::GetCard(backlog, idTarjeta1);
	cout << "Tarjetas primera entrega obtenidas" << endl;
	for (int i = 0; i < 3; ++i)
	{
		KanbanBoardColumn::RemoveCard(backlog, tareasPrimerEntrega[i]);
		KanbanBoardColumn::AddCard(terminado, tareasPrimerEntrega[i]);
	}
	cout << "Tarjetas primera entrega movidas" << endl;
}

void MostrarColumna(Column* columna)
{
	cout << KanbanBoardColumn::GetTitle(columna) << " (" << KanbanBoardState::GetName(KanbanBoardColumn::GetState(columna)) << " - Total: " << KanbanBoardColumn::CountCards(columna) << ")" << endl;
	Card* proximaTareaPrioritaria = KanbanBoardColumn::GetTopPriorityCard(columna);
	while (proximaTareaPrioritaria != NULL)
	{
		cout << "\t" << KanbanBoardCard::GetId(proximaTareaPrioritaria) << " " << KanbanBoardCard::GetName(proximaTareaPrioritaria) << endl;
		proximaTareaPrioritaria = KanbanBoardColumn::GetNextCard(columna, proximaTareaPrioritaria);
	}
}