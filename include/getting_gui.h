#ifndef GETTING_GUI_H
#define GETTING_GUI_H

#include <QDialog>

class QLabel;
class QLineEdit;
class QPushButton;
struct File_t;
class ErrorDialog;

class GettingDialog : public QDialog
{
	Q_OBJECT
public:
	GettingDialog( File_t* file, QWidget* parent = 0 );
	~GettingDialog( void );
signals:
	void finishInput( void );
public slots:
	void openDialog( void );
private slots:
	void check( void );
private:
	QLabel* label;
	QLineEdit* edit;
	QPushButton* okButton;
	QPushButton* closeButton;
	File_t* file;

	ErrorDialog* errorDialog;
};

#endif
