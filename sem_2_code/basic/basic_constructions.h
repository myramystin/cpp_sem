#pragma once  // директива препроцессора, которая предотвращает множественное включение одного и того же заголовочного файла.

namespace first {
    void Hello1();
}

namespace second {
    void Hello2();

namespace third {
     void Hello2();
}
}

namespace basic {
    bool DemonstrateConditions(int a);
    int DemonstrateConditions(int a, int b);
    int DemonstrateConditions(int a, int b, int c, int d = 0);

    void DemonstrateLoops(int a);
}

