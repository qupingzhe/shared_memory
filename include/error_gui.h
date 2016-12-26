#ifndef ERROR_GUI_H
#define ERROR_GUI_H

#include <QDialog>
#include <stdint.h>

class QLabel;
class QPushButton;

class ErrorDialog : public QDialog
{
	Q_OBJECT
public:
	ErrorDialog( QWidget* parent = 0 );
	~ErrorDialog( void );
	void setError( int type );

private:
	QLabel* label;
	QPushButton* button;

};

#endif
