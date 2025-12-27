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
    MediaFile * M[3];
    M[0]=&i;
    M[1]=&v;
    M[2]=&a;
    for(int j=0;j<3;j++){
        M[j]->play();
    }
    return 0;

    
}