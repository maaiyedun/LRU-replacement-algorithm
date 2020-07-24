#include<bits/stdc++.h>
using namespace std;
int main(){
	int cSize,pSize,i,j,k,hit=0;
	cout<<"Enter the cache Size"<< endl;
	cin>>cSize;

	cout<<"Enter the number of Processes"<< endl;
	cin>>pSize;

	vector<int> p(pSize);
	vector<int> hi(pSize);

	cout<<"Enter Processes"<< endl;
	for(i=0;i<pSize;i++){
		cin>>p[i];
	}
	vector<vector<int>> a(cSize);
	for(i=0;i<cSize;i++){
		a[i]=vector<int>(pSize,-1);
	}
	map <int, int> mp;
	for(i=0;i<pSize;i++){
		vector<pair<int,int>> c;
		for(auto q: mp){
			c.push_back({q.second,q.first});
		}
		sort(c.begin(),c.end());
		bool hasrun=false;
		for(j=0;j<cSize;j++){
			if(a[j][i]==p[i]){
				hit++;
				hi[i]=1;
				mp[p[i]]=1;
				hasrun=true;
				break;
			}
			if(a[j][i]==-1){
				for(k=i;k<pSize;k++)
					a[j][k]=p[i];
				mp[p[i]]++;
				hasrun=true;
				break;
			}
		}
		if(j==cSize||hasrun==false){
			for(j=0;j<cSize;j++){
				if(a[j][i]==c[c.size()-1].second){
					mp.erase(a[j][i]);
					for(k=i;k<pSize;k++)
						a[j][k]=p[i];
					mp[p[i]]++;
					break;
				}
			}
		}
		for(auto q:mp){
			if(q.first!=p[i]){
				mp[q.first]++;
			}
		}
	}
	cout<<"Process ";
	for(i=0;i<pSize;i++){
		cout<<p[i]<<" ";
	}
	cout<<endl;
	for(i=0;i<cSize;i++){
		cout<<"Frame "<<i<<" ";
		for(j=0;j<pSize;j++){
			if(a[i][j]==-1)
				cout<<"E ";
				else
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"HIT     ";
	for(i=0;i<pSize;i++){
		if(hi[i]==0)
		cout<<"  ";
		else
		cout<<hi[i]<<" ";
	}
	cout<<endl;
	cout<<"Page Hit "<<hit<<endl<<"Page Fault "<<pSize-hit<< endl;
	return 0;
}
