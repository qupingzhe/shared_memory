#ifndef ERROR_GUI_H
#define ERROR_GUI_H

#include <QDialog>
#include <stdint.h>
#include <shared_memory.h>

class QLabel;
class QPushButton;

class ErrorDialog : public QDialog
{
	Q_OBJECT
public:
	ErrorDialog( QWidget* parent );
	~ErrorDialog( void );
	void setError( int type );

private:
	QLabel* label;
	QPushButton* button;

};

#endif
