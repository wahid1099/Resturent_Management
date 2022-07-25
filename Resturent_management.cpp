// #include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Restaurant
{
    public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_prices[12];
    protected:
    float total_tax;
  public:
    void set_tax(float total_tax)
    {
        this->total_tax = total_tax;
    }

    int get_tax(){
        return this->total_tax;
    }
};

int main()
{

    Restaurant *restaurant=new Restaurant;
    cout<<"Enter Number of items you want to input : ";
    int n;
    cin >> n;

    for(int i=1;i<=n;i++){
      cout<<"Enter foode code "<< i<<": ";
        cin >>restaurant->food_item_codes[i];


        cout<<"Enter foode Item Name "<< i<<": ";
        cin.ignore();
        getline(cin,restaurant->food_item_names[i]);


        cout<<"Enter foode Item Price "<< i<<": ";
        cin >>restaurant->food_item_prices[i];

    }





     while(true){

         cout<<endl;
         cout<<endl;
         cout<<endl;

        cout<<"\t\tMake Billing"<<endl;


        cout<<"\t\t---------------------------------------"<<endl;

        cout<<setw(30)<<left<<"Item Code "<<setw(30)<<left<<"Item Name"<<setw(30)<<left<<"Item Price"<<endl;

        for(int i=1;i<=n;i++){


            cout<<setw(30)<<left<<restaurant->food_item_codes[i]<<setw(30)<<left<<restaurant->food_item_names[i]<<setw(30)<<left<<restaurant->food_item_prices[i]<<endl;
        }





        int table_no,nf;
        cout<<"Enter Table Number : ";
        cin>>table_no;

        cout<<"Enter no of items : ";
        cin>>nf;
        int no_of_items[nf],item_code[nf],item_quantity[nf];
        int total_price=0;
        float tax_amount;

        for(int i=1;i<=nf;i++){
            cout<<"Enter Item "<<i<<" Code : ";
            cin>>item_code[i];
            bool isFounded = false;

            for(int j=1;j<=n;j++){
                if(item_code[i]==restaurant->food_item_codes[j]){
                     isFounded=true;
                      break;

                }else{
                   
                    isFounded=false;
                    }

           }

            if(isFounded){
                    cout<<"Enter Item "<<i<<" quantity : ";
                      cin>>item_quantity[i];

                     }else{
                         cout<<"Invalid code ! "<<endl;
                    cout<<"Enter Item "<<i<<" Code : ";
                    cin>>item_code[i];
                   cout<<endl;
                    cout<<"Enter Item "<<i<<" quantity : ";
                      cin>>item_quantity[i];
                     }
           


        }

        cout<<endl;
        cout<<endl;
        cout<<endl;

         cout<<"\t\tBill Summary"<<endl;


        cout<<"\t\t---------------------------------------"<<endl;

       cout<<endl;
        cout<<"Table No : "<<table_no<<endl;
        cout<<endl;

        cout<<setw(30)<<left<<"Item Code "<<setw(30)<<left<<"Item Name"<<setw(30)<<left<<"Item Price"<<setw(30)<<left<<"Item Quantity"<<setw(30)<<left<<"Total Price"<<endl;

        for(int i=1;i<=n;i++){
           for(int j=1;j<=nf;j++){
            if(restaurant->food_item_codes[i]==item_code[j]){
                total_price+=restaurant->food_item_prices[i]*item_quantity[j];
                cout<<setw(30)<<left<<restaurant->food_item_codes[i]<<setw(30)<<left<<restaurant->food_item_names[i]<<setw(30)<<left<<restaurant->food_item_prices[i]<<setw(30)<<left<<item_quantity[j]<<setw(30)<<left<<restaurant->food_item_prices[i]*item_quantity[j]<<endl;

            }

           }
        }

        tax_amount=(total_price/100)*5;
        cout<<setw(120)<<left<<"TAX"<<setw(120)<<left<<tax_amount<<endl;
        cout<<"-----------------------------------------------------------------------------------------------------------------------------------"<<endl;
        cout<<setw(120)<<left<<"NET TOTAL"<<tax_amount+total_price<<" TAKA"<<endl;
        


        cout<<endl;

        restaurant->set_tax(tax_amount);

        cout<<"total tax is : "<<restaurant->get_tax()<<endl;



     }






  return 0;
}
