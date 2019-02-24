#include <iostream>
#include <cmath>
#include <Windows.h>
#include <fstream>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

int policz_czas(int R[],int P[],int Q[], int ilosc)
{
	int licz=0,sprawdz=0,czekanie=0;
	for (int i=0;i<ilosc;i++)
        {
		if(sprawdz<R[i]){
			licz=R[i]-sprawdz;
			sprawdz=R[i];
			sprawdz=sprawdz+P[i];
			if(czekanie>0){czekanie=czekanie-P[i]-licz;}
			if(czekanie<Q[i]){czekanie=Q[i];}}
		else{sprawdz=sprawdz+P[i];
            if(czekanie>0){czekanie=czekanie-P[i];}
			if(czekanie<Q[i]){czekanie=Q[i];}}
        }
	licz=sprawdz+czekanie;
	return licz;
}


void QuicksortUP( int R[],int P[],int Q[],int K[], int left, int right )
{
    int i = left;
    int j = right;
    int x = R[(left+right) / 2] ;
    do
    {
        while( R[i] < x )
             i++;
        while( R[j] > x )
             j--;
        if( i <= j )
        {
            swap(K[i],K[j]);
            swap(R[i],R[j]);
            swap(P[i],P[j]);
            swap(Q[i],Q[j]);
            i++;
            j--;
        }
    } while( i <= j );
    if( left < j ) QuicksortUP( R,P,Q,K, left, j );
    if( right > i ) QuicksortUP( R,P,Q,K, i, right );
}
void QuicksortDOWN( int R[],int P[],int Q[],int K[], int left, int right )
{
    int i = left;
    int j = right;
    int x = Q[(left+right) / 2] ;
    do
    {
        while( Q[i] > x )
             i++;
        while( Q[j] < x )
             j--;
        if( i <= j )
        {
            swap(K[i],K[j]);
            swap(R[i],R[j]);
            swap(P[i],P[j]);
            swap(Q[i],Q[j]);
            i++;
            j--;
        }
    } while( i <= j );
    if( left < j ) QuicksortDOWN( R,P,Q,K, left, j );
    if( right > i ) QuicksortDOWN( R,P,Q,K, i, right );
}

void Schrage(int R[],int P[],int Q[],int K[],int N)
{
    int tmp=0;
    int j=0;
//    int tmp1=0;
    QuicksortUP(R,P,Q,K,0,N-1);
    for(int i=0;i<N;i++)
    {
        QuicksortDOWN(R,P,Q,K,i,j);
        tmp=max(tmp,R[i])+P[i];
        while(tmp>R[j] && j<N){j++;} if(R[j]>tmp){j--;}
    }
    cout<<"cmax= "<<policz_czas(R,P,Q,N)<<endl;

    for(int i=0;i<N;i++)
    {
        cout<<K[i]<<" ";
    }
    cout<<endl<<endl;
}



void Schragepodz(int R[],int P[],int Q[],int K[],int N)
{
    int tmp=0;
    int cmax=0;
    int j=0;
    int tmp1=0;
    int tmp2=0;
    QuicksortUP(R,P,Q,K,0,N-1);
    for(int i=0;i<N;i++)
    {
        tmp1=0;
        tmp2=0;
        QuicksortDOWN(R,P,Q,K,i,j);
        cout<<endl;
        cout<<"TMP!!!!==="<<tmp<<endl;
        tmp=max(tmp,R[i])+P[i];
        cout<<"TMP!!!!==="<<tmp<<endl;
        cout<<endl;
        while(tmp>R[j] && j<=N){j++;} if(R[j]>=tmp){j--;}
        cout<<"Q[i]=   "<<Q[i]<<"\t"<<Q[i+1]<<"  = Q[i+1] "<<endl;
        cout<<"\t TMP=   "<<tmp<<"\t"<<cmax<<"   = cmax"<<endl;
        QuicksortDOWN(R,P,Q,K,i+1,j);
        if(Q[i]<Q[i+1])
        {

            cout<<"kropa"<<endl;
            tmp1=tmp-R[i+1];
            tmp=R[i+1]+tmp1;
            cout<<tmp1<<endl;

            if(tmp1>0)
            {
            cout<<"TMP!!!!==="<<tmp<<endl;
            //tmp=tmp-tmp1;
                tmp2=P[i];
                P[i]=tmp1;
                swap(R[i],R[i+1]);
                swap(P[i],P[i+1]);
                swap(Q[i],Q[i+1]);
                tmp+=tmp2-tmp1;
                cout<<endl<<"\tSWAPED!!!!"<<endl;

            }
                    cout<<"\t TMP=   "<<tmp<<"\t"<<cmax<<"   = cmax"<<endl;
        cout<<"R[i]=   "<<R[i]<<"\t"<<R[i+1]<<"  = R[i+1] "<<endl;
        cout<<"P[i]=   "<<P[i]<<"\t"<<P[i+1]<<"  = P[i+1] "<<endl;
        cout<<"Q[i]=   "<<Q[i]<<"\t"<<Q[i+1]<<"  = Q[i+1] "<<endl;

        }


       // tmp=tmp+P[i];
        cout<<"TMP!!!!2==="<<tmp<<endl;
        cmax=max(cmax,(tmp+Q[i]));

    }
    cout<<cmax<<endl;
  //
    cout<<"cmax= "<<policz_czas(R,P,Q,N)<<endl;

    for(int i=0;i<N;i++)
    {
        cout<<K[i]<<" ";
    }
    cout<<endl<<endl;
}

void Schragepodz1(int R[],int P[],int Q[],int K[],int N)
{
    int ile=0;
    int w[100];
    int k=0;
    int tmp=0;
    int cmax=0;
    int j=0;
    int tmp1=0;
    int tmp2=0;
    QuicksortUP(R,P,Q,K,0,N-1);
    for(int i=0;i<N;i++)
    {
        tmp1=0;
        tmp2=0;
        QuicksortDOWN(R,P,Q,K,i,j);
        tmp=max(tmp,R[i])+P[i];
        while(tmp>R[j] && j<=N){j++;} if(R[j]>=tmp){j--;}
        QuicksortDOWN(R,P,Q,K,i+1,j);
        if(Q[i]<Q[i+1])
        {
            tmp1=tmp-R[i+1];
            tmp=R[i+1]+tmp1;

            if(tmp1>0)
            {
                tmp2=P[i];
                P[i]=tmp1;
               // swap(R[i],R[i+1]);
                swap(P[i],P[i+1]);
                swap(Q[i],Q[i+1]);
                ile=-tmp1+tmp2;
               // Q[i]=Q[i]+ile;
               // P[i]=P[i]-ile;

                w[k]=tmp2-tmp1;
                k++;
            }
        }
        cmax=max(cmax,(tmp+Q[i]));
    }
   // cout<<cmax<<endl;
  //
  cout<<ile<<endl;
    cout<<"cmax= "<<policz_czas(R,P,Q,N)<<endl;

    for(int i=0;i<k;i++)
    {
        cout<<w[i]<<" ";
    }
    cout<<endl<<endl;
}




int main()
{
    int N;
    ifstream plik;
	plik.open("data000.txt");
	for(int ilosc=0;ilosc<8;ilosc++)
    {
        cout<<"data."<<ilosc<<endl;
	plik>>N;
	int R[N],P[N],Q[N],K[N];
	for (int i=0;i<N;i++)
    {
        K[i]=i+1;
        plik>>R[i]>>P[i]>>Q[i];
    }
    Schragepodz1(R,P,Q,K,N);
    }
    return 0;
}
