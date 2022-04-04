#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
void insertelement(ll &gd,ll &bc,map<ll,ll> &directory,map<ll,vector<ll>> &bucket,ll &in2,ll &counter,map<ll,ll> &creation,ll &start)
{
   ll divisor = pow(2, gd);
            ll k = in2 % divisor;
            k = directory[k];
            if (bucket[k].size() < bc + 1)
            {
                if(bucket[k].size()==0 && k>=pow(2,start))
                {
                   creation[counter]=k;
                   counter++;
                }
                bucket[k].push_back(in2);
                cout<<"Inserted successfully"<<endl;
            }
            else if (bucket[k].size() == bc + 1)
            {
                if (bucket[k][0] == gd)
                {
                    gd++;
                    if (gd < 20)
                    {
                        for (ll i = pow(2, gd - 1); i < pow(2, gd); i++)
                        {
                            directory[i] = directory[i - pow(2, gd - 1)];
                            bucket[i].push_back(bucket[directory[i]][0]);
                        }
                        directory[k + pow(2, gd - 1)] = k + pow(2, gd - 1);
                          creation[counter]=k + pow(2, gd - 1);
                          counter++;
                        bucket[k + pow(2, gd - 1)][0] = gd;
                        bucket[k][0] = gd;
                        vector<ll> temp;
                        for (ll i = bc; i >= 1; i--)
                        {
                            temp.push_back(bucket[k][i]);
                            bucket[k].pop_back();
                        }
                        temp.push_back(in2);
                        for (ll i = 0; i < temp.size(); i++)
                        {
                            // ll divisor = pow(2, gd);
                            // ll k = temp[i] % divisor;
                            // k = directory[k];

                            // bucket[k].push_back(temp[i]);
                            insertelement(gd,bc,directory,bucket,temp[i],counter,creation,start);
                        }
                        cout<<"Inserted successfully"<<endl;
          
                    }
                    else
                    {
                        cout << "Cannot be inserted"<<endl;
                      
                    }
                }
                else
                {
                    ll m = bucket[k][0];
                    directory[k + pow(2, m)] = k + pow(2, m);
                    creation[counter]=k + pow(2, m);
                    counter++;
                    bucket[k + pow(2, m)][0] = m + 1;
                    bucket[k][0] = m + 1;
                    vector<ll> temp;
                    for (ll i = bc; i >= 1; i--)
                    {
                        temp.push_back(bucket[k][i]);
                        bucket[k].pop_back();
                    }
                    temp.push_back(in2);
                    for (ll i = 0; i < temp.size(); i++)
                    {
                        // ll divisor = pow(2, m + 1);
                        // ll k = temp[i] % divisor;
                        // k = directory[k];

                        // bucket[k].push_back(temp[i]);
                        insertelement(gd,bc,directory,bucket,temp[i],counter,creation,start);
                    }
                    cout<<"Inserted successfully"<<endl;
          
                }
            }
}

int main()
{
    ll gd;
    cin >> gd;
    ll start =gd;
    map<ll, ll> directory;
    ll counter=0;
     map<ll,ll>creation;

    for (ll i = 0; i < pow(2, gd); i++)
    {
        directory[i] = i;
    }
    map<ll, vector<ll>> bucket;
        for (ll i = 0; i < pow(2, gd); i++)
    {
        bucket[i].push_back(gd);
    }
    for (ll i = 0; i < pow(2, gd); i++)
    {
        creation[counter]=i;
        counter++;
    }
   
    ll bc;
    cin >> bc;
    ll in1;
    ll in2;
    cin >> in1;

    while (in1 != 6)
    {
        //insertion
        if (in1 == 2)
        {
            cin >> in2;
            

            // ll divisor = pow(2, gd);
            // ll k = in2 % divisor;
            // k = directory[k];
            // if (bucket[k].size() < bc + 1)
            // {
            //     if(bucket[k].size()==0 && k>=pow(2,start))
            //     {
            //        creation[counter]=k;
            //        counter++;
            //     }
            //     bucket[k].push_back(in2);
            //     cout<<"Inserted successfully"<<endl;
            // }
            // else if (bucket[k].size() == bc + 1)
            // {
            //     if (bucket[k][0] == gd)
            //     {
            //         gd++;
            //         if (gd < 20)
            //         {
            //             for (ll i = pow(2, gd - 1); i < pow(2, gd); i++)
            //             {
            //                 directory[i] = directory[i - pow(2, gd - 1)];
            //                 bucket[i].push_back(bucket[directory[i]][0]);
            //             }
            //             directory[k + pow(2, gd - 1)] = k + pow(2, gd - 1);
            //             bucket[k + pow(2, gd - 1)][0] = gd;
              
            //        creation[counter]=k + pow(2, gd - 1);
            //        counter++;
                
            //             bucket[k][0] = gd;
            //             vector<ll> temp;
            //             for (ll i = bc; i >= 1; i--)
            //             {
            //                 temp.push_back(bucket[k][i]);
            //                 bucket[k].pop_back();
            //             }
            //             temp.push_back(in2);
            //             for (ll i = 0; i < temp.size(); i++)
            //             {
            //                 ll divisor = pow(2, gd);
            //                 ll k = temp[i] % divisor;
            //                 k = directory[k];

            //                 bucket[k].push_back(temp[i]);
            //             }
            //             cout<<"Inserted successfully"<<endl;
            //         }
            //         else
            //         {
            //             cout << "Cannot be inserted"<<endl;
            //             continue;
            //         }
            //     }
            //     else
            //     {
            //         ll m = bucket[k][0];

            //         directory[k + pow(2, m)] = k + pow(2, m);
            //         bucket[k + pow(2, m)][0] = m + 1;
            //         bucket[k][0] = m + 1;
            //         vector<ll> temp;
            //         for (ll i = bc; i >= 1; i--)
            //         {
            //             temp.push_back(bucket[k][i]);
            //             bucket[k].pop_back();
            //         }
            //         temp.push_back(in2);
            //         for (ll i = 0; i < temp.size(); i++)
            //         {
            //             ll divisor = pow(2, m + 1);
            //             ll k = temp[i] % divisor;
            //             k = directory[k];

            //             bucket[k].push_back(temp[i]);
            //         }
            //         cout<<"Inserted successfully"<<endl;
            //     }
            // }
            insertelement(gd,bc,directory,bucket,in2,counter,creation,start);
        }
        // search
        if(in1==3)
        {
            ll in2;
            cin>>in2;
            ll divisor = pow(2, gd);
            ll k = in2 % divisor;
            k = directory[k];
            ll bo=0;
            for (ll i = 1; i < bucket[k].size(); i++)
            {
                if(bucket[k][i]==in2)
                {
                    cout<<"Found"<<endl;
                    bo=1;
                    break;
                }

            }
            if(bo==0)
            {
                cout<<"Not found"<<endl;
            }
            
        }
        if (in1==4)
        {
            ll in2;
            cin>>in2;
            ll divisor = pow(2, gd);
            ll k = in2 % divisor;
            k = directory[k];
            ll bo=0;
            for (ll i = 1; i < bucket[k].size(); i++)
            {
                if(bucket[k][i]==in2)
                {
                    bo=i;
                    break;
                }

            }
            if(bo==0)
            {
                cout<<"Not found"<<endl;
            }
            else
            {
                vector<ll>temp;
                for (ll i = 1; i < bo; i++)
                {
                    temp.push_back(bucket[k][i]);
                    
                }
                for (ll i = bo+1; i < bucket[k].size(); i++)
                {
                    temp.push_back(bucket[k][i]);    
                }
                for (ll i = 0; i < bucket[k].size(); i++)
                {
                   bucket[k].pop_back();
                }
                for (ll i = 0; i < temp.size(); i++)
                {
                    bucket[k].push_back(temp[i]);
                }
                
                cout<<"Deleted successfully"<<endl;

                
                
            }
        }
        if(in1==5)
        {
            cout<<gd<<endl;
            cout<<creation.size()<<endl;
           
         for (auto i = creation.begin(); i != creation.end(); i++)
         {
          cout<<bucket[i->second].size()-1<<" "<<bucket[i->second][0]<<endl;
         }

         
            // for (ll i = 0; i < order.size(); i++)
            // {
            //     cout<<bucket[i]
            // }
            
            
        }
       ll g;
       cin>>g;
       in1=g;

    }
}