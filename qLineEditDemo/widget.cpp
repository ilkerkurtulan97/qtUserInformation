#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
#include <QDebug>
#include <QLineEdit>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //First Name
    QLabel * firstNameLabel = new QLabel("First Name",this);
    firstNameLabel->setMinimumSize(70,50);
    firstNameLabel->move(10,10);

    QLineEdit * firstNameLineEdit = new QLineEdit(this);
    firstNameLineEdit->setMinimumSize(200,50);
    firstNameLineEdit->move(100,10);

    //Last Name
    QLabel * lastNameLabel = new QLabel("Last Name",this);
    lastNameLabel->setMinimumSize(70,50);
    lastNameLabel->move(10,70);

    QLineEdit * lastNameLineEdit = new QLineEdit(this);
    lastNameLineEdit->setMinimumSize(200,50);
    lastNameLineEdit->move(100,70);

    //City Name
    QLabel * cityLabel = new QLabel("City",this);
    cityLabel->setMinimumSize(70,50);
    cityLabel->move(10,130);

    QLineEdit * cityLineEdit = new QLineEdit(this);
    cityLineEdit->setMinimumSize(200,50);
    cityLineEdit->move(100,130);

    QFont buttonFont("Times", 20, QFont::Bold);
    QPushButton * button = new QPushButton("Grab user data",this);
    button->setFont(buttonFont);
    button->move(80,190);

    connect(button,&QPushButton::clicked,[=](){
        QString firstName = firstNameLineEdit->text();
        QString lastName = lastNameLineEdit->text();
        QString city = cityLineEdit->text();

        qDebug() <<"First name is "<<firstName;
        qDebug() <<"Last name is "<<lastName;
        qDebug() <<"City name is "<<city;

        if( !firstName.isEmpty() && !lastName.isEmpty() && !city.isEmpty())
        {
            //If none of the fields are empty, program jumps on to here ! ! !
            qDebug() <<"First name is "<<firstName;
            qDebug() <<"Last name is "<<lastName;
            qDebug() <<"City name is "<<city;

        }
        else{
            qDebug() <<"One field is empty";
        }

    });

    /*
    //cursorPositionChanged
    connect(firstNameLineEdit,&QLineEdit::cursorPositionChanged,[=](){
        qDebug()<<"The current cursor position is : "<<firstNameLineEdit->cursorPosition();
    });
    */



    //editingFinished:
    /*
    connect(firstNameLineEdit,&QLineEdit::editingFinished,[=](){
        qDebug()<<"Editing has finished : ";
    });
    */


    //returnPressed
    /*
    connect(firstNameLineEdit,&QLineEdit::returnPressed,[=](){
        qDebug()<<"Return is pressed . ";

    });
    */

    /*
    connect(firstNameLineEdit,&QLineEdit::selectionChanged,[=](){
        qDebug()<<"Selection has changed : ";
    });
    */

    //textChanged

    /*
    connect(firstNameLineEdit,&QLineEdit::textChanged,[=](){
        qDebug()<<"Text has changed : "<<firstNameLineEdit->text();
    });
    */

    //textEdited

    connect(firstNameLineEdit,&QLineEdit::textEdited,[=](){
        qDebug()<<"Text has edited : "<<firstNameLineEdit->text();
    });

    //Change text in QLineEdit programatically
    /*
    lastNameLineEdit->setText("Your last name ");
    */

    //Hint text
    firstNameLineEdit->setPlaceholderText("First Name : ");
    lastNameLineEdit->setPlaceholderText("Last Name  : ");
    cityLineEdit->setPlaceholderText("City : ");





}

Widget::~Widget()
{

}

