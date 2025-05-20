//#include "widget.h"
/*
#include <QLabel>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel hello("<font color=red>"
                 "화염의 랜스 돌격!<i>Qt</i> </font>",nullptr);
    hello.resize(75,35);
    //Widget w;
    hello.show();
    return a.exec();
}*/

/*
#include <QLabel>
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPushButton quit("Quit");
    quit.resize(75,30);
    quit.show();
    QObject::connect(&quit,SIGNAL(clicked()),&a,SLOT(quit()));
    //quit.resize(75,35);
    //quit.show();
    return a.exec();
}*/

/*
#include <QLabel>         // QLabel: 텍스트나 HTML을 표시할 수 있는 위젯
#include <QApplication>   // QApplication: Qt 애플리케이션의 진입점
#include <QPushButton>    // QPushButton: 버튼 위젯
#include <QWidget>        // QWidget: 모든 위젯의 기본 클래스

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // Qt 애플리케이션 객체 생성

    QWidget w;                   // 메인 윈도우 위젯 생성

    // QLabel 위젯 생성, 부모는 w. HTML 형식으로 텍스트 지정 (파란색, 이탤릭체)
    QLabel hello("<font color='blue'>Hello <i>Qt!</i></font>", &w);
    hello.resize(120, 35);       // 레이블의 크기 지정

    // QPushButton 위젯 생성, 부모는 w, 텍스트는 "Quit"
    QPushButton quit("Quit", &w);
    quit.move(10, 40);           // quit 버튼 위치 지정 (x=10, y=40)
    quit.resize(75, 35);         // 버튼 크기 지정

    // quit 버튼이 클릭되면 hello 라벨의 텍스트를 굵게 "Hi"로 변경하는 람다 함수 연결
    QObject::connect(&quit, &QPushButton::clicked, &hello, [&]() {
        hello.setText("<b>Hi</b>");
    });

    //w.resize(150, 100);          // 메인 윈도우 크기 설정
    w.show();                    // 메인 윈도우 화면에 표시

    return a.exec();             // Qt 이벤트 루프 실행 (프로그램 실행 유지)
}*/

//2-1
/*
#include <QApplication>
#include "widget.h"

int main(int argc,char* argv[])
{
    QApplication a(argc, argv);

    Widget w;
    w.show();

    return a.exec();
}*/


//2-2
/*
#include <QApplication>
#include <QLabel>
#include "widget.h"

int main(int argc,char* argv[])
{
    QApplication a(argc, argv);

    Widget w;

    QLabel* label =new QLabel("<font size=20>Hello,World</font>", &w);
    label->setGeometry(10,90,75,35);

    w.show();

    return a.exec();
}*/


//2-3
/*
#include <QApplication>
#include <QLabel>
#include "widget.h"

int main(int argc,char* argv[])
{
    QApplication a(argc, argv);

    Widget w;

    QLabel* label =new QLabel("<font size=20>Hello,World</font>", &w);
    label->setGeometry(10,90,75,35);

    w.show();

    return a.exec();
}*/

//2-4 사용자 정의 시그널 예제
/*
#include <QApplication>
#include <QLabel>
#include "widget.h"

int main(int argc,char* argv[])
{
    QApplication a(argc, argv);

    Widget w;

    QLabel* label =new QLabel("<font size=20>Hello,World</font>", &w);
    label->setGeometry(10,90,75,35);

    QObject::connect(&w,SIGNAL(clicked()),&a,SLOT(quit()));

    w.show();

    return a.exec();
}*/


//3-1
/*
#include <QApplication>
#include <QLCDNumber>

int main(int argc, char* argv[])
{
    QApplication a(argc,argv);

    QLCDNumber* lcd =new QLCDNumber();
    //lcd->setBinMode();
    lcd ->setSegmentStyle(QLCDNumber::Flat);
    lcd -> display(2002);


    //lcd->setDigitCount(15)
    lcd->show();

    return a.exec();
}*/

/*
#include <QApplication>
#include <QLCDNumber>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    // LCD 디스플레이 생성
    QLCDNumber* lcd = new QLCDNumber();
    lcd->resize(250, 100);
    lcd->setSegmentStyle(QLCDNumber::Flat);
    lcd->setDigitCount(16);  // 충분한 자릿수 확보

    // 원하는 모드로 설정
    // QLCDNumber::Dec: 10진수 (기본)
    // QLCDNumber::Hex: 16진수
    // QLCDNumber::Oct: 8진수
    // QLCDNumber::Bin: 2진수

    int value = 2002;

    // 🔁 이 줄만 바꿔서 모드 테스트 가능
    lcd->setMode(QLCDNumber::Hex);  // 예: 16진수로 설정
    lcd->display(value);            // 값 표시

    lcd->show();

    return a.exec();
}*/


//3-2
/*
#include <QApplication>
#include <QProgressBar>

int main(int argc,char* argv[])
{
    QApplication a(argc, argv);

    QProgressBar* progBar = new QProgressBar();
    progBar->setValue(100);

    progBar->show();


    return a.exec();
}*/

//3-3 수정전
/*
#include <QApplication>
#include <QProgressBar>
#include <QTime>

int main(int argc,char* argv[])
{
    QApplication a(argc, argv);

    QProgressBar* progBar = new QProgressBar();
    progBar->show();

    QTimer timer;
    int n = 0;
    QObject::connect(&timer,&QTimer::timeout,[&]{progbar->Value(++n%101)});

    timer(100);

    return a.exec();
}*/
/*
#include <QApplication>
#include <QProgressBar>
#include <QTimer>        // 타이머 포함

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    // 프로그레스바 생성
    QProgressBar* progBar = new QProgressBar();
    progBar->setRange(0, 100);  // 0~100 범위 설정
    progBar->show();

    // 타이머와 증가 변수 설정
    QTimer timer;
    int n = 0;

    // 타이머 연결 (100ms마다 값 증가)
    QObject::connect(&timer, &QTimer::timeout, [&]() {
        progBar->setValue(n++ % 101);  // 0~100까지 반복
    });

    // 타이머 시작 (100ms 간격)
    timer.start(10);

    return a.exec();
}*/


//3-4@@@@@@@@@@@@@@@
/*
#include <QApplication>
#include <QTextBrowser>
#include <QUrl>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    QTextBrowser* tb = new QTextBrowser();
    tb->setSource(QUrl("index.html"));
    tb->show();

    return a.exec();
}*/



//3-5
/*
#include <QApplication>
#include<QPushButton>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    QPushButton* pushButton = new QPushButton("Push&Button",nullptr);
    pushButton->setCheckable(true);
    QObject::connect(pushButton,&QPushButton::toggled,[&](bool flag){qDebug()<<"toggled";if(!flag)a.quit();});

    pushButton->show();

    return a.exec();
}*/



//3-6
/*
#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Widget w;    // 사용자 정의 위젯
    w.setWindowTitle("QRadioButton Example");
    w.show();    // 창 보이기

    return app.exec();  // 이벤트 루프 실행
}*/

//3-7
/*
#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;
    w.setWindowTitle("QCheckBox with Slots");
    w.show();

    return a.exec();
}*/

//3-8 QSlider 예제
/*
#include <QApplication>
#include <QSlider>
#include <QStyleFactory>

int main(int argc, char* argv[])
{
    QApplication a(argc,argv);

    QSlider* slider = new QSlider();
    slider -> setOrientation(Qt::Horizontal);
    slider -> setTickPosition(QSlider::TicksAbove);
    slider -> setStyle(QStyleFactory::create("Fusion"));
    slider -> show();

    return a.exec();
}*/

//3-8-2 교수님 예제
/*
#include <QProgressBar>
#include <QSlider>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget w;

    QProgressBar bar(&w);
    bar.setGeometry(10, 10, 150, 20);

    QSlider slider(&w);
    slider.setGeometry(10, 40, 150, 20);
    slider.setOrientation(Qt::Horizontal);

    QObject::connect(&slider, SIGNAL(valueChanged(int)), &bar, SLOT(setValue(int)));

    w.show();
    return a.exec();
}*/


//3-9
/*
#include <QApplication>
#include <QScrollBar>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget window;
    window.setWindowTitle("QScrollBar Example");
    window.resize(200, 150);

    // 스크롤바 생성
    QScrollBar *scrollBar = new QScrollBar(Qt::Vertical);
    scrollBar->setRange(0, 100);
    scrollBar->setPageStep(10);  // 한 페이지 단위 이동
    scrollBar->setSingleStep(1); // 한 칸 단위 이동

    // 현재 값을 표시할 라벨 생성
    QLabel *label = new QLabel("Value: 0");

    // 레이아웃 설정
    QVBoxLayout *layout = new QVBoxLayout(&window);
    layout->addWidget(scrollBar);
    layout->addWidget(label);

    // 스크롤바 값 변경 시 라벨에 출력
    QObject::connect(scrollBar, &QScrollBar::valueChanged, [=](int value){
        label->setText(QString("Value: %1").arg(value));
    });

    window.show();
    return a.exec();
}*/
//3-9-2
/*
#include <QApplication>
#include <QScrollBar>
#include <QLabel>
#include <QScrollArea>
#include <QPalette>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 긴 텍스트를 가진 QLabel 생성
    QLabel* label = new QLabel("1234567890123456789012345678901234567890");

    // QScrollArea 생성
    QScrollArea* scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark); // 배경색 설정
    scrollArea->setWidget(label);                  // 라벨을 스크롤 영역에 넣음
    scrollArea->resize(60, 30);                    // 뷰포트 크기 설정

    scrollArea->show(); // 오타 수정: shoe() → show()

    // 수평 스크롤바를 맨 끝으로 이동
    QScrollBar* slider = scrollArea->horizontalScrollBar();
    slider->setValue(slider->maximum());

    return a.exec();
}*/

//3-10
/*
#include <QApplication>
#include <QDial>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    QDial* dial = new QDial();
    dial->setWrapping(true);
    dial->setNotchesVisible(true);
    dial->setNotchTarget(10);
    dial->show();

    return a.exec();
}*/

//3-11
/*
#include <QApplication>
#include <QSpinBox>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    // 스핀박스 생성
    QSpinBox* spinBox = new QSpinBox();

    // 입력 가능한 값 범위 설정 (0 ~ 10)
    spinBox->setRange(0, 10);

    // 값 뒤에 "%" 기호를 붙임 (예: 3%)
    spinBox->setSuffix("%");

    // wrapping 설정: 최대값에서 증가하면 최소값으로 다시 돌아감 (순환)
    spinBox->setWrapping(true);

    // 위젯 화면에 표시
    spinBox->show();

    return a.exec();
}*/

//3-12
//QTimeEdit & QDateEdit 예제 전체 코드
/*
#include <QApplication>
#include <QTimeEdit>
#include <QDateEdit>
#include <QVBoxLayout>
#include <QWidget>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    // 메인 위젯 생성
    QWidget window;
    window.setWindowTitle("QTimeEdit & QDateEdit Example");

    // 시간 편집 위젯
    QTimeEdit* timeEdit = new QTimeEdit(QTime::currentTime());
    timeEdit->setDisplayFormat("HH:mm:ss"); // 시간 포맷 설정

    // 날짜 편집 위젯
    QDateEdit* dateEdit = new QDateEdit(QDate::currentDate());
    dateEdit->setDisplayFormat("yyyy-MM-dd"); // 날짜 포맷 설정
    dateEdit->setCalendarPopup(true);         // 캘린더 팝업 사용

    // 레이아웃 설정
    QVBoxLayout* layout = new QVBoxLayout(&window);
    layout->addWidget(timeEdit);
    layout->addWidget(dateEdit);

    // 화면에 표시
    window.show();

    return a.exec();
}*/


//3-13 echomode 속성
/*
#include <QApplication>
#include <QLineEdit>
#include <QCompleter>
#include <QStringList>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    // QLineEdit 생성
    QLineEdit *lineEdit = new QLineEdit();

    // 자동완성에 사용할 문자열 리스트
    QStringList CompletionList;
    CompletionList << "Bryan" << "Bart" << "kelvin" << "Beth" << "Brad" << "kelly";

    // QCompleter 생성 (두 번째 인자는 부모: lineEdit)
    QCompleter *stringCompleter = new QCompleter(CompletionList, lineEdit);
    stringCompleter->setCaseSensitivity(Qt::CaseInsensitive); // 대소문자 무시

    // QLineEdit에 completer 연결
    lineEdit->setCompleter(stringCompleter);

    lineEdit->show();

    return a.exec();
}*/

//3-14
/*
#include <QApplication>
#include <QLineEdit>

int main (int argc,char *argv[])
{
    QApplication a(argc,argv);

    QLineEdit* lineEdit = new QLineEdit();
}
*/


//3-15 정규표현
#include <QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}



