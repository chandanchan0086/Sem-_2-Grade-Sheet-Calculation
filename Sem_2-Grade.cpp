#include <iostream>
#include <string.h>
#include <map>
#include <vector>
#include <cmath>
#include<numeric>
#include <fstream>
using namespace std;
class StudentDetail{
  public:
    string student_name;
    int roll_number;
    string branch;
    std::map<string, vector<double>> student_marks;
    double gpa_1;
    vector<int> final_grade;
    double grade_total;
    double gpa_2;
};
StudentDetail stu1_object;
void endSemMarks(double marks,double* end_marks,double* total_marks)
{
    *end_marks = 0.5 * marks + 2.5 * stu1_object.gpa_1;
    double rounded_end_marks = round(*end_marks);
    cout << "External Marks :: " << *end_marks << " round of to : " << rounded_end_marks << endl;
    *end_marks = rounded_end_marks;
    *total_marks = *end_marks + marks;
    cout << "Total Marks :: " << *total_marks << endl;
}
void Grade_calc(double total_marks,double *grade_num,int i)
{
    if(total_marks >= 90 && total_marks <=100)
    {
        cout << " A+\n";
        *grade_num=10;
    }
    else if(total_marks >= 80 && total_marks <=89)
    {
        cout << " A\n";
        *grade_num=9;
    }
    else if(total_marks >= 70 && total_marks <=79)
    {
        cout << " B\n";
        *grade_num=8;
    }
    else if(total_marks >= 60 && total_marks <=69)
    {
        cout << " C\n";
        *grade_num=7;
    }
    else if(total_marks >= 50 && total_marks <=59)
    {
        cout << " D\n";
        *grade_num=6;
    }
    else if(total_marks >= 40 && total_marks <=49)
    {
        cout << " E\n";
        *grade_num=5;
    }
    else if(total_marks < 40)
    {
        cout << " Fail\n";
        *grade_num=4;
    }
    if(i==0 || i==2 || i==4 || i==6 || i==8)
    {
        stu1_object.final_grade.push_back(*grade_num * 3);
    }
    else if(i==10)
    {
        stu1_object.final_grade.push_back(*grade_num*4);
    }
    else
    {
        stu1_object.final_grade.push_back(*grade_num);
    }
}
int main()
{
    fstream new_file;
    new_file.open("result_sheet.txt",ios::out);
    int branch_sel;
    cout << "Enter the Student Name : ";
    getline(cin,stu1_object.student_name);
    cout << "Enter the Roll Number : ";
    cin >> stu1_object.roll_number;
    cout << "\nEnter the SGPA of 1-sem : ";
    cin >> stu1_object.gpa_1;
    bool branch_check = true;
    int i;
    double marks;
    while(branch_check)
    {
        cout << "\nSelect Branch :: 1-> Embedded Systems\n\t\t 2-> VLSI Design\n\t\t 3-> Big Data\n\t\t 4-> Cloud Computing\n\t\t 5-> Healthcare";
        cout << "\nEnter option :: ";
        cin >> branch_sel;
        if (branch_sel > 0 && branch_sel <= 5)
        {
            branch_check = false;
        }
        else
        {
            cout << "\n### Enter a valid option ###";
        }
    }
    vector<string> SubList;
    vector<double> value;
    double end_marks,total_marks;
    double grade_num;
    cout << "---Refer SLCM---";
    cout << "\nSubjects : \n";
    switch(branch_sel)
	{
		case 1:
		{
		    stu1_object.branch="Embedded Systems";
			SubList={"DSP\t","DSP-Lab\t","DD\t","DD-Lab\t","ES\t","ES-lab\t","ESD\t","ESD-Lab\t","Elective-II","Elective-II-Lab","Project-2","Seminar-2"};
			for(i=0;i<SubList.size()-2;i++)
			{
			    cout << "\t\t " << SubList[i] << "\nEnter the IA marks(50) : ";
			    cin >> marks;
			    value.push_back(marks);
			    endSemMarks(marks,&end_marks,&total_marks);
                value.push_back(end_marks);
                value.push_back(total_marks);
                Grade_calc(total_marks,&grade_num,i);
                value.push_back(grade_num);
			    stu1_object.student_marks.insert({SubList[i],value});
			    value.clear();
			}
			value.push_back(0);
			value.push_back(0);
            cout << "\t\t " << SubList[i] << "\nEnter the marks(100) : ";
            cin >> marks;
            value.push_back(marks);
            Grade_calc(marks,&grade_num,i);
            value.push_back(grade_num);
            stu1_object.student_marks.insert({SubList[i],value});
            value.clear();
            value.push_back(0);
			value.push_back(0);
			i++;
            cout << "\t\t " << SubList[i] << "\nEnter the marks(100) : ";
            cin >> marks;
            value.push_back(marks);
            Grade_calc(marks,&grade_num,i);
            value.push_back(grade_num);
            stu1_object.student_marks.insert({SubList[i],value});
            value.clear();
			break;
		}
		case 2:
		{
		    stu1_object.branch="VLSI Design";
			SubList={"AVD\t","AVD-Lab\t","LPVD\t","LPVD-Lab\t","UVM\t","UVM-Lab\t","S-VLSI\t","S-VLSI-Lab\t","Elective-II","Elective-II-Lab","Project-2","Seminar-2"};
			for(i=0;i<SubList.size()-2;i++)
			{
			    cout << "\t\t " << SubList[i] << "\nEnter the IA marks(50) : ";
			    cin >> marks;
			    value.push_back(marks);
                endSemMarks(marks,&end_marks,&total_marks);
                value.push_back(end_marks);
                value.push_back(total_marks);
                Grade_calc(total_marks,&grade_num,i);
                value.push_back(grade_num);
			    stu1_object.student_marks.insert({SubList[i],value});
			    value.clear();
			}
            value.push_back(0);
			value.push_back(0);
            cout << "\t\t " << SubList[i] << "\nEnter the marks(100) : ";
            cin >> marks;
            value.push_back(marks);
            Grade_calc(marks,&grade_num,i);
            value.push_back(grade_num);
            stu1_object.student_marks.insert({SubList[i],value});
            value.clear();
            value.push_back(0);
			value.push_back(0);
			i++;
            cout << "\t\t " << SubList[i] << "\nEnter the marks(100) : ";
            cin >> marks;
            value.push_back(marks);
            Grade_calc(marks,&grade_num,i);
            value.push_back(grade_num);
            stu1_object.student_marks.insert({SubList[i],value});
            value.clear();
			break;
		}
		case 3:
		{
		    stu1_object.branch="Big Data";
			SubList={"ABDS\t","ABDS-Lab\t","MLR & LR\t","MLR & LR-Lab","ML-BD\t","ML-BD-Lab","HI\t","HI-Lab\t","Elective-II","Elective-II-Lab","Project-2","Seminar-2"};
			for(i=0;i<SubList.size()-2;i++)
			{
			    cout << "\t\t " << SubList[i] << "\nEnter the IA marks(50) : " ;
			    cin >> marks;
			    value.push_back(marks);
                endSemMarks(marks,&end_marks,&total_marks);
                value.push_back(end_marks);
                value.push_back(total_marks);
                Grade_calc(total_marks,&grade_num,i);
                value.push_back(grade_num);
			    stu1_object.student_marks.insert({SubList[i],value});
			    value.clear();
			}
			value.push_back(0);
			value.push_back(0);
            cout << "\t\t " << SubList[i] << "\nEnter the marks(100) : ";
            cin >> marks;
            value.push_back(marks);
            Grade_calc(marks,&grade_num,i);
            value.push_back(grade_num);
            stu1_object.student_marks.insert({SubList[i],value});
            value.clear();
            value.push_back(0);
			value.push_back(0);
			i++;
            cout << "\t\t " << SubList[i] << "\nEnter the marks(100) : ";
            cin >> marks;
            value.push_back(marks);
            Grade_calc(marks,&grade_num,i);
            value.push_back(grade_num);
            stu1_object.student_marks.insert({SubList[i],value});
            value.clear();
			break;
		}
		case 4:
		{
		    stu1_object.branch="Cloud Computing";
			SubList={"CN\t","CN-Lab\t","CS\t","CS-Lab\t","CDM\t","CDM-Lab\t","BD & DV\t","BD & DV-Lab","Elective-II","Elective-II-Lab","Project-2","Seminar-2"};
			for(i=0;i<SubList.size()-2;i++)
			{
			    cout << "\t\t " << SubList[i] << "\nEnter the IA marks(50) : " ;
			    cin >> marks;
			    value.push_back(marks);
                endSemMarks(marks,&end_marks,&total_marks);
                value.push_back(end_marks);
                value.push_back(total_marks);
                Grade_calc(total_marks,&grade_num,i);
                value.push_back(grade_num);
			    stu1_object.student_marks.insert({SubList[i],value});
			    value.clear();
			}
			value.push_back(0);
			value.push_back(0);
            cout << "\t\t " << SubList[i] << "\nEnter the marks(100) : ";
            cin >> marks;
            value.push_back(marks);
            Grade_calc(marks,&grade_num,i);
            value.push_back(grade_num);
            stu1_object.student_marks.insert({SubList[i],value});
            value.clear();
            value.push_back(0);
			value.push_back(0);
			i++;
            cout << "\t\t " << SubList[i] << "\nEnter the marks(100) : ";
            cin >> marks;
            value.push_back(marks);
            Grade_calc(marks,&grade_num,i);
            value.push_back(grade_num);
            stu1_object.student_marks.insert({SubList[i],value});
            value.clear();
			break;
		}
		case 5:
		{
		    stu1_object.branch="Healthcare";
			SubList={"MLR & LR\t","MLR & LR-Lab","ML-BD\t","ML-BD-Lab","BD-H\t","BD-H-Lab","MIS\t","MIS-Lab\t","Elective-II","Elective-II-Lab","Project-2","Seminar-2"};
			for(i=0;i<SubList.size()-2;i++)
			{
			    cout << "\t\t " << SubList[i] << "\nEnter the IA marks(50) : " ;
			    cin >> marks;
			    value.push_back(marks);
			    endSemMarks(marks,&end_marks,&total_marks);
                value.push_back(end_marks);
                value.push_back(total_marks);
                Grade_calc(total_marks,&grade_num,i);
                value.push_back(grade_num);
			    stu1_object.student_marks.insert({SubList[i],value});
			    value.clear();
			}
			value.push_back(0);
			value.push_back(0);
            cout << "\t\t " << SubList[i] << "\nEnter the marks(100) : ";
            cin >> marks;
            value.push_back(marks);
            Grade_calc(marks,&grade_num,i);
            value.push_back(grade_num);
            stu1_object.student_marks.insert({SubList[i],value});
            value.clear();
            value.push_back(0);
			value.push_back(0);
			i++;
            cout << "\t\t " << SubList[i] << "\nEnter the marks(100) : ";
            cin >> marks;
            value.push_back(marks);
            Grade_calc(marks,&grade_num,i);
            value.push_back(grade_num);
            stu1_object.student_marks.insert({SubList[i],value});
            value.clear();
			break;
		}
	}
    stu1_object.grade_total = accumulate(stu1_object.final_grade.begin(),stu1_object.final_grade.end(),0);;
    stu1_object.gpa_2 = stu1_object.grade_total/25.0;

    if(!new_file)
    {
        cout<<"\nFile creation failed\n";
    }
    else
    {
        cout<<"\nFor Result File Check => FILE name >>> result_sheet.txt <<<\n###(Located at program file's location)###\n";
        new_file << "----------------------------------------------------------------\n";
        new_file << "\tMANIPAL SCHOOL OF INFORMATION SCIENCES\n";
        new_file << "\t\t    Grade Sheet\nSemester: 2\n";
        new_file << "----------------------------------------------------------------\n";
        new_file << "Name: " << stu1_object.student_name<< "\t" << "Roll Num: " << stu1_object.roll_number << "\t" << "Branch: " << stu1_object.branch << endl;
        new_file << "----------------------------------------------------------------\n";
        new_file << "Sem-1 SGPA : " << stu1_object.gpa_1 ;
        new_file << "\nDetailed Marks : " << endl;
        new_file << "Subject\t\t\tIA-1\tExt\tTotal\tGrade\t" << endl;
        new_file << "----------------------------------------------------------------\n";
        for(auto detail : stu1_object.student_marks)
        {
            new_file << detail.first << "\t\t: ";
            for(auto d : detail.second)
            {
                new_file << d << "\t";
            }
            new_file << "\n";
        }
        new_file << "----------------------------------------------------------------\n";
        new_file << "Sem-2 SGPA : " << stu1_object.gpa_2 ;
        new_file << "\n----------------------------------------------------------------\n";
        new_file << "1st Year CGPA : " << (stu1_object.gpa_1 + stu1_object.gpa_2)/2.0 ;
        new_file << "\n----------------------------------------------------------------\n";
        new_file.close();
    }
    cout << "\nThe Student Name :: " << stu1_object.student_name << endl;
    cout << "Register Number :: " << stu1_object.roll_number << endl;
    cout << "Branch ::" << stu1_object.branch << endl;
    cout << "SGPA of 1-Sem : " << stu1_object.gpa_1 << endl;
    cout << "\nDetail Marks " << endl;
    cout << "Subject\t\tIA-1\tExt\tTotal\tGrade" << endl;

    for(auto detail : stu1_object.student_marks)
    {
        cout << detail.first << "\t: " ;
        for(auto d : detail.second)
        {
            cout << d << "\t" ;
        }
        cout << "\n" ;
    }
    cout << "----------------------------------------------\n";
    cout << "Sem-2 SGPA : " << stu1_object.gpa_2;
    cout << "\n----------------------------------------------";
    cout << "\n1st Year CGPA : " << (stu1_object.gpa_1 + stu1_object.gpa_2)/2.0 ;
    cout << "\n----------------------------------------------";
    cout << "\nDeveloped by Chandan BR[Embedded System-A]\nThank You..,\n";
}
