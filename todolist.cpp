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

    /*Задаем обозначение для поставленных задач*/
    QLabel* plblPending = new QLabel("Выполнить", this);
    plblPending->setStyleSheet("font-size: 15pt;");
    pHLayoutLabels->addWidget(plblPending);

    /*Задаем обозначение для выполненных задач*/
    QLabel* plblCompleted = new QLabel("Выполнено", this);
    plblCompleted->setStyleSheet("font-size: 15pt;");
    pHLayoutLabels->addWidget(plblCompleted);

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


    /*Задаются цвет и формы таблички поставленных задач*/
    m_pwPending->setStyleSheet
    ("QListView { font-size: 20pt; font-weight: bold; }"
     "QListView::item { background-color: #E74C3C; padding: 10%;"
     "border: 1px solid #C0392B; }"
     "QListView::item::hover { background-color: #C0392B }");

    /*Задаются цвет и формы таблички выполненных задач*/
    m_pwCompleted->setStyleSheet
    ("QListView { font-size: 20pt; font-weight: bold; }"
     "QListView::item { background-color: #2ECC71; padding: 10%;"
     "border: 1px solid #27AE60; }"
     "QListView::item::hover { background-color: #27AE60 }");


    QToolBar* pToolBar = new QToolBar(this);
    addToolBar(pToolBar);

    /*Задаем триггер добавления новой задачи и обозначаем его картинкой*/
    m_pActAdd = new QAction(this);
    m_pActAdd->setIcon(QIcon(":/resources/add.png"));
    connect(m_pActAdd, &QAction::triggered, this, &CToDoList::onAdd);

    /*Задаем триггер удаления задачи и обозначаем его картинкой*/
    m_pActRemove = new QAction(this);
    m_pActRemove->setIcon(QIcon(":/resources/remove.png"));
    connect(m_pActRemove, &QAction::triggered, this, &CToDoList::onRemove);

    /*Добавляем действия*/
    pToolBar->addAction(m_pActAdd);
    pToolBar->addAction(m_pActRemove);
}


void CToDoList::onAdd()
{

}


void CToDoList::onRemove()
{

}
