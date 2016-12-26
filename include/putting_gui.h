#ifndef PUTTING_GUI_H
#define PUTTING_GUI_H

#include <QDialog>

class QLabel;
class QLineEdit;
class QTextEdit;
class QPushButton;

struct File_t;
class ErrorDialog;

class PuttingDialog : public QDialog
{
	Q_OBJECT
public:
	PuttingDialog( File_t* file, QWidget* parent = 0 );
	~PuttingDialog( void );
signals:
	void finishInput( void );
public slots:
	void openDialog( void );
private slots:
	void check( void );
private:
	QLabel* label;
	QLineEdit* nameEdit;
	QTextEdit* dataEdit;
	QPushButton* okButton;
	QPushButton* closeButton;

	ErrorDialog* errorDialog;
	File_t *file;
};

#endif
