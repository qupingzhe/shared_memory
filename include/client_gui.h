#ifndef CLIENT_GUI_H
#define CLIENT_GUI_H

#include <QMainWindow>

class QPushButton;
class QTextEdit;

class Client;
class SuccessDialog;
class ErrorDialog;
class PuttingDialog;
class GettingDialog;
struct File_t;

class ClientMainWindow : public QMainWindow
{
	Q_OBJECT
public:
	ClientMainWindow( void );
	~ClientMainWindow( void );
	void initiate( void );
	void initiateConnection( void );
	void initiateLayout( void );

private slots:
	void applyBlock( void );
	void releaseBlock( void );
	void getFile( void );
	void putFile( void );
	void showDirectory( void );

private:
	QWidget* mainWidget;
	QPushButton* applyingBlockButton;
	QPushButton* releasingBlockButton;

	QPushButton* gettingFileButton;
	QPushButton* puttingFileButton;

	QPushButton* showingDirectoryButton;
	QTextEdit* textEdit;

	Client* client;
	struct File_t* file;
	SuccessDialog* successDialog;
	ErrorDialog* errorDialog;
	GettingDialog* gettingDialog;
	PuttingDialog* puttingDialog;

};

#endif
