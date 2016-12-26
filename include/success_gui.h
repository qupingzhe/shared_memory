#ifndef SUCCESS_GUI_H
#define SUCCESS_GUI_H

#include <QDialog>

class QLabel;
class QPushButton;

class SuccessDialog : public QDialog
{
public:
	SuccessDialog( QWidget* parent = 0 );
	~SuccessDialog( void );
	void setSuccess( int type );
private:
	QLabel* label;
	QPushButton* button;
};

#endif
