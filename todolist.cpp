#include "todolist.h"

#include <QLabel>
#include <QToolBar>
#include <QBoxLayout>
#include <QDebug>

CToDoList::CToDoList()
{
    /*Задаем основное окно*/
    QWidget* pWidget = new QWidget(this);
    pWidget->setStyleSheet(" width: 150px; background-color: #FFFFFF");
    setCentralWidget(pWidget);

    QVBoxLayout* pMainLayout = new QVBoxLayout();
    pWidget->setLayout(pMainLayout);

    /*Задаем и располагаем титульный заголовок*/
    QLabel* pwTitle = new QLabel("Список дел", this);
    pMainLayout->addWidget(pwTitle);
    pwTitle->setAlignment(Qt::AlignCenter);
    pwTitle->setStyleSheet("font-size: 30pt; margin: 10%;");

    QHBoxLayout* pHLayoutLabels = new QHBoxLayout();
    pMainLayout->addLayout(pHLayoutLabels);



    QHBoxLayout* pHLayout = new QHBoxLayout();
    pMainLayout->addLayout(pHLayout);


    m_pwPending = new QListView(this);

    /*Добавляем виджет*/
    pHLayout->addWidget(m_pwPending);



    m_pwCompleted = new QListView(this);


    /*Добавляем виджет*/
    pHLayout->addWidget(m_pwCompleted);


    m_pwPending->setModel(new QStringListModel());
    m_pwCompleted->setModel(new QStringListModel());

}


void CToDoList::onAdd()
{

}


void CToDoList::onRemove()
{

}
