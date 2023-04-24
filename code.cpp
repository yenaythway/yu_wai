#include <list>
#include "iostream"
#include "string"
using namespace std;
int admin_or_user();

class Athlete{
    int id;//
    string name;//
    int lev_option;
    int current_weight;
    int competition_weight;
    string athlete_level;
    int private_op;
    double total_fees=0;
    double user_tution_hr;
    double num_of_compt_this_month;
    string trainer_name[5]={"Trainer A","Trainer B","Trainer C","Trainer D","Trainer E"};
    double beginner_trainning_fee=25.00;
    double intermediate_trainning_fee=30.00;
    double elite_trainning_fee=35.00;
    double private_tution_per_hr=9.50;
    double competition_entry_fee_per_compition=22.00;
    int weight_list[6]={100,100,90,81,73,66};
    int heavy_weight=100;
    int light_heavy_weight=100;
    int middle_weight=90;
    int light_middle_weight=81;
    int light_weight=73;
    int fly_weight=66;
public:
    void view_trainning_plan(int flag);
    void registration();
    int trainning_info_and_fees();
    void view_weight_categories();
    void view_trainer_and_price();
    void output();

};
void Athlete::view_trainer_and_price() {
    cout<<"Trainer name       Price\n";
    int ind= sizeof(trainer_name)/ sizeof(trainer_name[0]);
    for(int i=0;i< ind;i++){
        cout<<trainer_name[i]<<"          $9.50\n";
    }

}
void Athlete::view_trainning_plan(int flag) {

    cout<<"This is Trainning plan"<<endl<<endl;
//    cout<<"Athlete level                                    : Fees"<<endl;
    cout<<"1-Beginner (2 sessions per week)-weekly fee        :"<<beginner_trainning_fee<<"$"<<endl;
    cout<<"2-Intermediate (3 sessions per week)-weekly fee    :"<<intermediate_trainning_fee<<"$"<<endl;
    cout<<"3-Elite (5 sessions per week)-weekly fee           :"<<elite_trainning_fee<<"$"<<endl;
    if(flag==1){
        cout<<"Private tution per hour                          :"<<private_tution_per_hr<<"$"<<endl;
        cout<<"Competition entry fee per competition            :"<<competition_entry_fee_per_compition<<"$"<<endl;
    }

}
void Athlete::view_weight_categories() {
    cout<<"This is weight categories(kg)\n";
    cout<<"1-Heavy weight:Unlimited (over"<<heavy_weight<<")\n";
    cout<<"2-Light Heavy weight:"<<light_heavy_weight<<"\n";
    cout<<"3-Middle weight:"<<middle_weight<<"\n";
    cout<<"4-Light middle weight:"<<light_middle_weight<<"\n";
    cout<<"5-Light weight:"<<light_weight<<"\n";
    cout<<"6-Fly weight:"<<fly_weight<<"\n";
}
void Athlete::output(){
//    total_fees=(competition_entry_fee_per_compition*num_of_compt_this_month);

    cout<<"\nThis is output\n"
          "| ################################################################################\n";
    cout<<"| Id"<<id;
    cout<<"\n| Athlete name:"<<name;
    cout<<"\n| ________________________________________________________________________________";
    cout<<"\n|                   Itemised list of all costs for month";
    cout<<"\n| ________________________________________________________________________________";
    if(lev_option==1){
        cout<<"\n| Beginner (8 sessions per month)-monthly fee : "<<beginner_trainning_fee*4<<"$";
        cout<<"\n| As u are beginner there is no cost for competiton";
        total_fees=total_fees+(beginner_trainning_fee*4);
    }else if(lev_option==2){
        cout<<"\n| Intermediate (12 sessions per month)-monthly fee    :"<<intermediate_trainning_fee*4<<"$";
        cout<<"\n| Competition entry fee per competition            :"<<competition_entry_fee_per_compition*num_of_compt_this_month<<"$";
        total_fees=total_fees+(intermediate_trainning_fee*4)+(competition_entry_fee_per_compition*num_of_compt_this_month);
    } else if(lev_option==3){
        cout<<"\n| Elite (20 sessions per month)-monthly fee           :"<<elite_trainning_fee*4<<"$";
        cout<<"\n| Competition entry fee per competition            :"<<competition_entry_fee_per_compition*num_of_compt_this_month<<"$";
        total_fees=total_fees+(elite_trainning_fee*4)+(competition_entry_fee_per_compition*num_of_compt_this_month);
    }
    if(private_op==1){
        cout<<"\n| Private tution per hour                          :"<<private_tution_per_hr*user_tution_hr<<"$";
        total_fees=total_fees+(private_tution_per_hr*user_tution_hr);
    }

    cout<<"\n| ###################################################################################";
    cout<<"\n| The total cost of trainning and competitions for the month : "<<total_fees<<"$\n";
    cout<<"\nYour current weight is =>"<<current_weight<<"kg";
    cout<<"\nYour competition weight is =>"<<weight_list[competition_weight]<<"kg";
    int dif_weight=current_weight-weight_list[competition_weight];
    if(competition_weight==1){
        if(dif_weight<0){
            cout<<"\nYou need to weight gain"<<dif_weight*(-1)<<"kg";
        } else if(dif_weight>=0){
            cout<<"\nYour weight is ready to perticipate";
        }
    } else{
        if(dif_weight<0){
            cout<<"\nYou need to weight loss "<<dif_weight<<"kg";

        }else if(dif_weight==0){
            cout<<"\nYour weight is equal to upper weight limit";
        }else{
            cout<<"\nYou need to weight gain"<<dif_weight*(-1)<<"kg";
        }
    }



}
int Athlete::trainning_info_and_fees() {
    view_trainning_plan(0);
    flag3:
    cout<<"Enter your plan number that u want to buy(1 or 2 etc...)";
//    cout<<"Enter your plan that u want to buy\n1-Beginner\n2-Intermediate\n3-Elite\n4-View plan\n";
    cin>>lev_option;
//    cout<<lev_option;
    if(lev_option==2 || lev_option==3){
        cout<<"Number of competitions entered this month:";
        cin>>num_of_compt_this_month;
        view_weight_categories();
        cout<<"Enter compiton weight category that u want to perticipate(1 or 2 etc..):\n";
        cin>>competition_weight;
    } else if(lev_option==1){
        cout<<"Only intermediate and elite athletes can enter competions\n";

    }else{
        cout<<"Invalid input\n";
        goto flag3;
    }
    flag4:

    cout<<"If u want private coaching enter 1 \nIf u don't want enter 2 : ";
    cin>>private_op;
    if(private_op==1){
        flag2:
        cout<<"Enter number of hour for private coaching a week : ";
        cin>>user_tution_hr;
        if(user_tution_hr<5){
            output();
        } else{
            cout<<"Athletes can receive a maximum of five hour's private coaching a week";
            goto flag2;
        }
    }else if(private_op==2){
        output();
    }else{
        goto flag4;
    }
//    cout<<"Pay "<<beginner_trainning_fee<<"$ for Beginner plan\n";
//    cin>>user_plan_fee;
//    if((lev_option==1 && user_plan_fee==beginner_trainning_fee)||(lev_option==2 && user_plan_fee==intermediate_trainning_fee)||(lev_option==3&& user_plan_fee==elite_trainning_fee)){

//    }else {
//        cout<<"Invaild option or amount\n";
//        trainning_info_and_fees();
//        return 0;
//    }
    return 0;
}
void Athlete::registration() {
    cout<<"Enter name : "<<endl;
//    getline(cin,name);
    cin>>name;
//    cout<<name;
    cout<<"Enter your current weight in kg : "<<endl;
    cin>>current_weight;
    trainning_info_and_fees();

}

class Admin{

};
int main(){
    admin_or_user();
}
int admin_or_user(){
    int option;
    cout<<"Enter option 1 or 2\n1-Admin\n2-Athlete : ";
    cin>>option;
    if(option==1){
        Admin admin;
    }else if(option==2){
        Athlete athlete;
        int user_op;
        flag1:
        cout<<"\n\nEnter option \n1-View Trainer and trainner price\n2-View trinning plan\n3-Registration\n4-Exit : ";
        cin>>user_op;
        if(user_op==1){
            athlete.view_trainer_and_price();
            goto flag1;
        }else if(user_op==2){
            athlete.view_trainning_plan(1);
            goto flag1;
        } else if(user_op==3){
            athlete.registration();
            goto flag1;
        } else if(user_op==4){
            exit(1);
        } else{
            cout<<"Invalid input\n";
            goto flag1;
        }
    }else{
        cout<<"Invalid input\n";
        admin_or_user();
        return 0;
    }
    return 0;
}
