#include<iostream>
using namespace std;
class MediaFile {
    public:
    virtual  void play()=0;
};
class Audio:public MediaFile{
    public:
    void play()override{
        cout<<"play the music"<<endl;
    }

};
class Vedio:public MediaFile{
    public:
    void play()override{
        cout<<"play the vedio"<<endl;
    }

};
class Image:public MediaFile{
    public:
    void play()override{
        cout<<"play the image"<<endl;
    }

};
int main(){
    Image i;
    Vedio v;
    Audio a;
    MediaFile * m;
    m=&i;
    m->play();
    m=&v;
    m->play();
    m=&a;
    m->play();
    return 0;
}