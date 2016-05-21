#include <iostream>
using namespace std;

class IAudio {
public:
    virtual void CreatAudio () = 0;
    virtual void AttachAudio () = 0;
};

class IVideo {
public:
    virtual void CreatVideo () = 0;
    virtual void AttachVideo () = 0;
};

class IMagnifier {
public:
    virtual void CreatMagnifier () = 0;
    virtual void AttachMagnifier () = 0;
};

class IFactory {
public:
    virtual IAudio * BuildAudio () = 0;
    virtual IVideo * BuildVideo () = 0;
    virtual IMagnifier * BuildMagnifier () = 0;
};

/* IE browser*/
class IEAudio: public IAudio {
public:
    virtual void CreatAudio () {
        cout << "IEAudio Created" << endl;
    }
    virtual void AttachAudio () {
        cout << "IEAudio Attached" << endl;
    }
};

class IEVideo: public IVideo {
public:
    virtual void CreatVideo () {
        cout << "IEVideo Created" << endl;
    }
    virtual void AttachVideo () {
        cout << "IEVideo Attached" << endl;
    }
};

class IEMagnifier: public IMagnifier {
public:
    virtual void CreatMagnifier () {
        cout << "IEMagnifier Created" << endl;
    }
    virtual void  AttachMagnifier () {
        cout << "IEMagnifier Attached" << endl;
    }
};

class IEFactory: public IFactory {
public: 
    virtual IAudio *BuildAudio () {
        return new IEAudio();
    }
    virtual IVideo *BuildVideo () {
        return new IEVideo();
    }
    virtual IMagnifier *BuildMagnifier () {
        return new IEMagnifier();
    }
};
/* End IE browser*/

/* Chrome */
class ChromeAudio: public IAudio {
public:
    virtual void CreatAudio () {
        cout << "ChromeAudio Created" << endl;
    }
    virtual void AttachAudio () {
        cout << "ChromeAudio Attached" << endl;
    }
};

class ChromeVideo: public IVideo {
public:
    virtual void CreatVideo () {
        cout << "ChromeVideo Created" << endl;
    }
    virtual void AttachVideo () {
        cout << "ChromeVideo Attached" << endl;
    }
};

class ChromeMagnifier: public IMagnifier {
public:
    virtual void CreatMagnifier () {
        cout << "ChromeMagnifier Created" << endl;
    }
    virtual void  AttachMagnifier () {
        cout << "ChromeMagnifier Attached" << endl;
    }
};

class ChromeFactory: public IFactory {
public: 
    virtual IAudio *BuildAudio () {
        return new ChromeAudio();
    }
    virtual IVideo *BuildVideo () {
        return new ChromeVideo();
    }
    virtual IMagnifier *BuildMagnifier () {
        return new ChromeMagnifier();
    }
};
/* End Chrome browser*/

class FactoryDecider {
public:
    static IFactory *CreateBrowserData(int param) {
        // get details from param return respected data
        return new ChromeFactory();
    }
};

int main (void) {

    IFactory *fact = FactoryDecider::CreateBrowserData (1);
    IAudio *aud = fact->BuildAudio ();
    aud-> CreatAudio();
    aud-> AttachAudio();
    cout << "------------------------------------------------" << endl << endl;
    
    IVideo *vid = fact->BuildVideo ();
    vid-> CreatVideo();
    vid-> AttachVideo();
    cout << "------------------------------------------------" << endl << endl;
    
    IMagnifier *mag = fact->BuildMagnifier ();
    mag-> CreatMagnifier();
    mag-> AttachMagnifier();
    cout << "------------------------------------------------";
    
    cout << endl << endl;
    return 0;
}