#include <iostream>

using std::string, std::cout, std::endl;

class AbstractEmployee {
    virtual void askForPromotion() = 0;  // Pure virtual function: it must be implemented by all children of this class.
};

class Employee : AbstractEmployee {
    private:
        string company;
        int age;
    protected:
        string name;
    public:
        Employee(string name, string company, int age) {
            this->name = name;
            this->company = company;
            this->age = age;
        }

        void introduceMyself() {
            cout << "Name:    " << this->name << endl;
            cout << "Company: " << this->company << endl;
            cout << "Age:     " << this->age << endl;
        }

        void askForPromotion() {
            if (this->age > 29) {
                cout << this->name << " got promoted\n";
            } else {
                cout << this->name << " can't be promoted\n";
            }
        }

        virtual void work() {
            cout << this->name << " is working...\n";
        }

        void setName(string name) {
            this->name = name;
        }

        void setCompany(string comp) {
            company = comp;
        }

        void setAge(int age) {
            this->age = age;
        }

        string getName() {
            return this->name;
        }

        string getCompany() {
            return this->company;
        }

        int getAge() {
            return this->age;
        }
};

class Developer : public Employee {
    private:
        string favProgLang;

    public:
        Developer(string name, string company, int age, string favProgLang) : Employee(name, company, age) {
            this->favProgLang = favProgLang;
        }

        void fixBug() {
            cout << this->name << " fixed bug using " << this->favProgLang << endl;
        }

        void work() {
            cout << this->name << " is making some codes in " << this->favProgLang << endl;
        }

        void setFavProgLang(string setFavProgLang) {
            this->favProgLang = favProgLang;
        }

        string getFavProg() {
            return this->favProgLang;
        }

};

class Teacher : Employee {
    private:
        string subject;
    public:
        Teacher(string name, string company, int age, string subject) : Employee(name, company, age) {
            this->subject = subject;
        }

        void prepareLesson() {
            cout << this->name << " prepared a " << this->subject << " lesson\n";
        }

        void work() {
            cout << this->name << " is teaching " << this->subject << endl;
        }

        void setSubject(string subject) {
            this->subject = subject;
        }

        string getSubject() {
            return this->subject;
        }
};

int main() {
    Employee e1 = Employee("Daniel", "Google", 30);
    e1.introduceMyself();
    e1.askForPromotion();
    Developer d1("Marinna", "Microsoft", 25, "Python");
    d1.introduceMyself();
    d1.fixBug();
    Teacher t1("Mark", "Super Teacher College", 35, "Distributed Systems");
    // t1.introduceMyself();  // Compile-time error: Teacher does not inherit publicly from Employee.
    t1.prepareLesson();
    t1.work();
    Employee* ep = &e1;
    ep->work();
    ep = &d1;
    ep->work();
    // ep = &t1;  // Compile-time error: Teacher does not inherit publicly from Employee.

    return 0;
}
