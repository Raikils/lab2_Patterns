#include <QtTest>
#include <QCoreApplication>
#include "MemoryUsage.h"
#include "MemoryUsage.cpp"
#include "Visitor.h"
#include "Visitor.cpp"
#include "Strategy.h"
#include "Strategy.cpp"
#include "Decorator.h"
#include "Decorator.cpp"
#include "Timer.h"
#include "Timer.cpp"
#include <QDebug>
#include <string>

// add necessary includes here

class Tests : public QObject
{
    Q_OBJECT

public:
    Tests();
    ~Tests();

private slots:
    void CheckNaive();
    void CheckRabina_Karpa();
    void CheckHorspool();
    void CheckKMP();
    void CheckBoyer_Moor();
    void cleanupTestCase();
    void test_case1();

};

Tests::Tests()
{

}

Tests::~Tests()
{

}

void Tests::CheckNaive()
{
        Substring_Search_Algorithms_* a = new Substring_Search_Algorithms_(new Naive);
        QVERIFY(a->Search("abjfjdihfdn.dds123da","fdn.dds1") == 8);
        QVERIFY(a->Search("ldmemmvlds,l;sllel,e22","e22") == 19);
        QVERIFY(a->Search("","fdn.dds1") == -1);
        QVERIFY(a->Search("","") == -1);
        QVERIFY(a->Search("fsawdsadsa","") == -1);
        QVERIFY(a->Search("dwdewfewfewf","dwdewf") == 0);
        QVERIFY(a->Search("vsdffefefewfewfefdscwefewf","efefewfewfefds1") == -1);
        QVERIFY(a->Search("rvrfrfwwfdsfvcxdwewfew","fwwfdsfvcxdwew2") == -1);
        QVERIFY(a->Search("vjmfkmkrmfkewmflkmejkwnfgnrjkgnjknrjgnfrwknfjknwjnflewngljfnlgnjlrenfjgnrejnglk;ergregq","mejkwnfgnrjkgnjknrjgnfrw") == 17);
        QVERIFY(a->Search("ytjytjytjteyjejruyfjgifmdkgimikfdimgp","ytjytjteyjejruyfjgifmdkgimikfdi") == 3);
        QVERIFY(a->Search("1234567888654351332","78886543") == 6);
        QVERIFY(a->Search("43jirm4j3fij3ji4f3f4i34-f","m4j3fij3ji4f3f") == 5);
        QVERIFY(a->Search("1111","11111") == -1);
        QVERIFY(a->Search("gregergerfes","greger") == 0);
}

void Tests::CheckRabina_Karpa()
{
    Substring_Search_Algorithms_* a = new Substring_Search_Algorithms_(new Rabina_Karpa);
    QVERIFY(a->Search("abjfjdihfdn.dds123da","fdn.dds1") == 8);
    QVERIFY(a->Search("ldmemmvlds,l;sllel,e22","e22") == 19);
    QVERIFY(a->Search("","fdn.dds1") == -1);
    QVERIFY(a->Search("","") == -1);
    QVERIFY(a->Search("fsawdsadsa","") == -1);
    QVERIFY(a->Search("dwdewfewfewf","dwdewf") == 0);
    QVERIFY(a->Search("vsdffefefewfewfefdscwefewf","efefewfewfefds1") == -1);
    QVERIFY(a->Search("rvrfrfwwfdsfvcxdwewfew","fwwfdsfvcxdwew2") == -1);
    QVERIFY(a->Search("vjmfkmkrmfkewmflkmejkwnfgnrjkgnjknrjgnfrwknfjknwjnflewngljfnlgnjlrenfjgnrejnglk;ergregq","mejkwnfgnrjkgnjknrjgnfrw") == 17);
    QVERIFY(a->Search("ytjytjytjteyjejruyfjgifmdkgimikfdimgp","ytjytjteyjejruyfjgifmdkgimikfdi") == 3);
    QVERIFY(a->Search("1234567888654351332","78886543") == 6);
    QVERIFY(a->Search("43jirm4j3fij3ji4f3f4i34-f","m4j3fij3ji4f3f") == 5);
    QVERIFY(a->Search("1111","11111") == -1);
    QVERIFY(a->Search("gregergerfes","greger") == 0);
}

void Tests::CheckHorspool()
{
    Substring_Search_Algorithms_* a = new Substring_Search_Algorithms_(new Horspool);
    QVERIFY(a->Search("abjfjdihfdn.dds123da","fdn.dds1") == 8);
    QVERIFY(a->Search("ldmemmvlds,l;sllel,e22","e22") == 19);
    QVERIFY(a->Search("","fdn.dds1") == -1);
    QVERIFY(a->Search("","") == -1);
    QVERIFY(a->Search("fsawdsadsa","") == -1);
    QVERIFY(a->Search("dwdewfewfewf","dwdewf") == 0);
    QVERIFY(a->Search("vsdffefefewfewfefdscwefewf","efefewfewfefds1") == -1);
    QVERIFY(a->Search("rvrfrfwwfdsfvcxdwewfew","fwwfdsfvcxdwew2") == -1);
    QVERIFY(a->Search("vjmfkmkrmfkewmflkmejkwnfgnrjkgnjknrjgnfrwknfjknwjnflewngljfnlgnjlrenfjgnrejnglk;ergregq","mejkwnfgnrjkgnjknrjgnfrw") == 17);
    QVERIFY(a->Search("ytjytjytjteyjejruyfjgifmdkgimikfdimgp","ytjytjteyjejruyfjgifmdkgimikfdi") == 3);
    QVERIFY(a->Search("1234567888654351332","78886543") == 6);
    QVERIFY(a->Search("43jirm4j3fij3ji4f3f4i34-f","m4j3fij3ji4f3f") == 5);
    QVERIFY(a->Search("1111","11111") == -1);
    QVERIFY(a->Search("gregergerfes","greger") == 0);
}

void Tests::CheckKMP()
{
    Substring_Search_Algorithms_* a = new Substring_Search_Algorithms_(new KMP);
    QVERIFY(a->Search("abjfjdihfdn.dds123da","fdn.dds1") == 8);
    QVERIFY(a->Search("ldmemmvlds,l;sllel,e22","e22") == 19);
    QVERIFY(a->Search("","fdn.dds1") == -1);
    QVERIFY(a->Search("","") == -1);
    QVERIFY(a->Search("fsawdsadsa","") == -1);
    QVERIFY(a->Search("dwdewfewfewf","dwdewf") == 0);
    QVERIFY(a->Search("vsdffefefewfewfefdscwefewf","efefewfewfefds1") == -1);
    QVERIFY(a->Search("rvrfrfwwfdsfvcxdwewfew","fwwfdsfvcxdwew2") == -1);
    QVERIFY(a->Search("vjmfkmkrmfkewmflkmejkwnfgnrjkgnjknrjgnfrwknfjknwjnflewngljfnlgnjlrenfjgnrejnglk;ergregq","mejkwnfgnrjkgnjknrjgnfrw") == 17);
    QVERIFY(a->Search("ytjytjytjteyjejruyfjgifmdkgimikfdimgp","ytjytjteyjejruyfjgifmdkgimikfdi") == 3);
    QVERIFY(a->Search("1234567888654351332","78886543") == 6);
    QVERIFY(a->Search("43jirm4j3fij3ji4f3f4i34-f","m4j3fij3ji4f3f") == 5);
    QVERIFY(a->Search("1111","11111") == -1);
    QVERIFY(a->Search("gregergerfes","greger") == 0);
}

void Tests::CheckBoyer_Moor()
{
    Substring_Search_Algorithms_* a = new Substring_Search_Algorithms_(new Boyer_Moor);
    QVERIFY(a->Search("abjfjdihfdn.dds123da","fdn.dds1") == 8);
    QVERIFY(a->Search("ldmemmvlds,l;sllel,e22","e22") == 19);
    QVERIFY(a->Search("","fdn.dds1") == -1);
    QVERIFY(a->Search("","") == -1);
    QVERIFY(a->Search("fsawdsadsa","") == -1);
    QVERIFY(a->Search("dwdewfewfewf","dwdewf") == 0);
    QVERIFY(a->Search("vsdffefefewfewfefdscwefewf","efefewfewfefds1") == -1);
    QVERIFY(a->Search("rvrfrfwwfdsfvcxdwewfew","fwwfdsfvcxdwew2") == -1);
    QVERIFY(a->Search("vjmfkmkrmfkewmflkmejkwnfgnrjkgnjknrjgnfrwknfjknwjnflewngljfnlgnjlrenfjgnrejnglk;ergregq","mejkwnfgnrjkgnjknrjgnfrw") == 17);
    QVERIFY(a->Search("ytjytjytjteyjejruyfjgifmdkgimikfdimgp","ytjytjteyjejruyfjgifmdkgimikfdi") == 3);
    QVERIFY(a->Search("1234567888654351332","78886543") == 6);
    QVERIFY(a->Search("43jirm4j3fij3ji4f3f4i34-f","m4j3fij3ji4f3f") == 5);
    QVERIFY(a->Search("1111","11111") == -1);
    QVERIFY(a->Search("gregergerfes","greger") == 0);
}

void Tests::cleanupTestCase()
{

}

void Tests::test_case1()
{

}

QTEST_MAIN(Tests)

#include "tst_tests.moc"
