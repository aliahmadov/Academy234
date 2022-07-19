using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Boss.AZ_Project_CSharp
{

    class Human
    {
        public static int Human_Id { get; set; }
        public int Id { get; set; }

        public int Age { get; set; }
        public string Username { get; set; }

        public string Password { get; set; }
        public string Name { get; set; }

        public string Surname { get; set; }

        public string City { get; set; }

        public string Phone { get; set; }

        public List<Notification> Notifications { get; set; } = new List<Notification>();

        public Human()
        {
            Id = ++Human_Id;
        }

        public void AddNotification(Notification notification)
        {
            Notifications.Add(notification);
        }

        public void ShowNotifications()
        {
            if (Notifications.Count > 0)
            {

                for (int i = 0; i < Notifications.Count; i++)
                {
                    Notifications[i].ShowNotification();
                }
            }
            else
            {
                Console.ForegroundColor = ConsoleColor.Red; Console.WriteLine("No Notifications Yet"); Console.ResetColor();
            }
        }
        public void Show()
        {
            Console.WriteLine($@"
ID: {Id}
Name: {Name}
Surname: {Surname}
Age: {Age}
City: {City}
Phone: {Phone}");
        }
    }

    class Worker : Human
    {
        public List<CV> CVs { get; set; } = new List<CV>();
        public int CvCount { get; set; } = 0;
        public void ShowCVs()
        {
            Console.WriteLine($"\nName : {Name}");
            Console.WriteLine($"Surname: {Surname}");
            Console.WriteLine();
            for (int i = 0; i < CvCount; i++)
            {
                CVs[i].Show();
            }
        }

        public void AddCV(CV cv)
        {
            CvCount++;
            CVs.Add(cv);
        }
    }

    class CV
    {
        public int Id { get; set; }

        public static int CV_Id { get; set; } = 0;
        public string Speciality { get; set; }
        public string School { get; set; }

        public string UniScore { get; set; }

        public List<string> Skills { get; set; } = new List<string>();
        public List<string> Companies { get; set; } = new List<string>();

        public DateTime BeginDate { get; set; }

        public DateTime EndDate { get; set; }

        public List<string> Languages { get; set; } = new List<string>();

        public bool HasCertificate { get; set; }

        public List<string> Links { get; set; } = new List<string>();

        public CV()
        {
            Id = ++CV_Id;
        }

        public void AddCompany(string company)
        {
            Companies.Add(company);
        }
        public void AddSkill(string skill)
        {
            Skills.Add(skill);
        }

        public void AddLanguage(string language)
        {
            Languages.Add(language);
        }

        public void AddLink(string link)
        {
            Links.Add(link);
        }

        public void ShowSkills()
        {
            Console.WriteLine("Skills  :  ");
            foreach (var skil in Skills)
            {
                Console.WriteLine(skil);
            }
            Console.WriteLine();
        }

        public void ShowLanguages()
        {
            Console.WriteLine("Languages  :  ");
            foreach (var language in Languages)
            {
                Console.WriteLine(language);
            }
            Console.WriteLine();
        }

        public void ShowLinks()
        {
            Console.WriteLine("Links  :  ");
            foreach (var link in Links)
            {
                Console.WriteLine(link);
            }
            Console.WriteLine();
        }

        public void ShowCompanies()
        {
            Console.WriteLine("Companies  :  ");
            foreach (var company in Companies)
            {
                Console.WriteLine(company);
            }
            Console.WriteLine();
        }
        public void Show()
        {
            Console.WriteLine($@" 
CV ID:  {Id}

Speciality : {Speciality}
School : {School}
University Score : {UniScore}
Begin work date : {BeginDate.ToShortDateString()}
End work date : {EndDate.ToShortDateString()}
----------------------------------------------------------             
");
            ShowLanguages();
            ShowSkills();
            ShowLinks();
            Console.WriteLine("===========================================================   ");
        }
    }


    class Vacancy
    {
        public static int Vac_Id { get; set; } = 0;
        public int Id { get; set; }

        public DateTime BeginTime { get; set; }
        public DateTime ExpiredTime { get; set; }
        public string Email { get; set; }

        public string Phones { get; set; }

        public string Category { get; set; }

        public string Position { get; set; }

        public string City { get; set; }

        public string MinSalary { get; set; }

        public string MaxSalary { get; set; }

        public string MinAge { get; set; }

        public string MaxAge { get; set; }

        public string Education { get; set; }

        public string ExperienceDuration { get; set; }

        public string Requirements { get; set; }

        public string AboutWork { get; set; }

        public string CompanyName { get; set; }

        public List<Applier> Appliers { get; set; } = new List<Applier>();

        public void AddApplier(Applier applier)
        {
            Appliers.Add(applier);
        }

        public Applier GetApplierByID(int id)
        {
            for (int i = 0; i < Appliers.Count; i++)
            {
                if (Appliers[i].Id == id)
                {
                    return Appliers[i];
                }
            }
            return null;
        }
        public void RemoveApplier(int id)
        {
            var applier = GetApplierByID(id);

            if (applier != null)
            {
                Appliers.Remove(applier);
            }
        }
        public Vacancy()
        {
            BeginTime = DateTime.Now;
            ExpiredTime = DateTime.Now.AddMonths(1);
            Id = ++Vac_Id;
        }

        public void ShowAppliers()
        {
            for (int i = 0; i < Appliers.Count; i++)
            {
                Appliers[i].ShowApplier();
            }
        }
        public void ShowVacancy()
        {
            Console.WriteLine($@"
Vacancy ID : {Id}

{Category} / {Position} 

{MinSalary}  -  {MaxSalary}  AZN    

Company Name : {CompanyName}
=========================================
");
        }

        public void ShowVacancyDetailed()
        {
            Console.WriteLine($@"
{Category}                             ID: {Id}

{Position}


{MinSalary} - {MaxSalary}  AZN                     Company Name :  {CompanyName}


City :  {City}                                      Phone : {Phones}
Age Requirement : {MinAge}-{MaxAge}                   Email : {Email}  
Education :  {Education}
Work Experience : {ExperienceDuration}
Begin Date: {BeginTime}
End Date : {ExpiredTime}

About Work:
{AboutWork}                                
Requirements: 
{Requirements}
");
        }

    }

    class Applier
    {
        public int Id { get; set; }
        public static int App_ID { get; set; } = 0;
        public Worker worker { get; set; }

        public CV Cv { get; set; }
        public DateTime ApplyDate { get; set; }

        public Applier()
        {
            Id = ++App_ID;
            ApplyDate = DateTime.Now;
        }


        public void ShowApplier()
        {
            Console.WriteLine($"\nFullname: {worker.Name}  {worker.Surname}");
            Console.WriteLine($"Applier ID: {Id}");
            Console.WriteLine($"Worker ID: {worker.Id}");
            Console.WriteLine($"Apply Date: {ApplyDate}");
            Console.WriteLine("========================================");
        }
    }

    class Notification
    {
        public static int N_Id { get; set; }
        public int Id { get; set; }
        public string Message { get; set; }

        public DateTime Time { get; set; }

        public Notification()
        {
            Id = ++N_Id;
            Time = DateTime.Now;
        }

        public void ShowNotification()
        {
            Console.WriteLine($"Notification ID: {Id}");
            Console.WriteLine($"Content: {Message}");
            Console.WriteLine($"Date: {Time}");
        }

    }

    class Employer : Human
    {
        public List<Vacancy> Vacancies { get; set; } = new List<Vacancy>();
        public int VacancyCount { get; set; }

        public void AddVacancy(Vacancy vacancy)
        {
            VacancyCount++;
            Vacancies.Add(vacancy);
        }

        public void ShowVacanciesDetailed()
        {
            if (Vacancies.Count == 0)
            {
                Console.ForegroundColor = ConsoleColor.Red; Console.WriteLine("You dont have any vacancy yet"); Console.ResetColor();
                Console.ReadKey();
            }
            else
            {
                for (int i = 0; i < VacancyCount; i++)
                {
                    Vacancies[i].ShowVacancyDetailed();
                }

            }
        }

        public void ShowSimpleVacancies()
        {
            if (Vacancies.Count != 0)
            {
                for (int i = 0; i < Vacancies.Count; i++)
                {
                    Vacancies[i].ShowVacancy();
                }
            }
        }

        public Vacancy GetVacancyById(int id)
        {
            for (int i = 0; i < Vacancies.Count; i++)
            {
                if (Vacancies[i].Id == id)
                {
                    return Vacancies[i];
                }
            }
            return null;
        }


        public void ShowAppliers(int id)
        {
            var vacancy = GetVacancyById(id);
            if (vacancy != null)
            {

                if (vacancy.Appliers.Count != 0)
                {

                    vacancy.ShowAppliers();
                }
                else
                {
                    Console.ForegroundColor = ConsoleColor.Red; Console.WriteLine("No appliers yet"); Console.ResetColor();
                }
            }
            else
            {
                throw new NotFoundByEnteredIDException();
            }
        }

    }



    class DataBase
    {
        public List<Employer> Employers { get; set; } = new List<Employer>();
        public List<Worker> Workers { get; set; } = new List<Worker>();

        public void AddWorker(Worker worker)
        {
            Workers.Add(worker);
        }

        public void AddEmployer(Employer employer)
        {
            Employers.Add(employer);
        }

        public void AddNotificationToEmployer(Notification notification,int vacancy_id)
        {
            for (int i = 0; i < Employers.Count; i++)
            {
                for (int k = 0; k < Employers[i].Vacancies.Count; k++)
                {
                    if (Employers[i].Vacancies[k].Id == vacancy_id)
                    {
                        Employers[i].AddNotification(notification);
                    }
                }
            }
        }
        public void AddNotificationToWorker(Notification notification, int worker_id)
        {
            for (int i = 0; i < Workers.Count; i++)
            {
                if (Workers[i].Id == worker_id)
                {
                    Workers[i].AddNotification(notification);
                }
            }
        }

        public void RemoveApplier(int id)
        {
            for (int i = 0; i < Employers.Count; i++)
            {
                for (int k = 0; k < Employers[i].Vacancies.Count; k++)
                {
                    for (int j = 0; j < Employers[i].Vacancies[k].Appliers.Count; j++)
                    {
                        if (Employers[i].Vacancies[k].Appliers[j].Id == id)
                        {
                            Employers[i].Vacancies[k].Appliers.RemoveAt(j);
                        }
                    }
                }
            }

        }
        //public void RemoveApplier(Applier applier, int vacancy_id)
        //{
        //    int index=GetIndexOfApplier(applier.Id);
        //    for (int i = 0; i < Employers.Count; i++)
        //    {
        //        for (int k = 0; k < Employers[i].Vacancies.Count; k++)
        //        {
        //            if (Employers[i].Vacancies[k].Id == vacancy_id)
        //            {
        //                Employers[i].Vacancies[k].Appliers.RemoveAt(index);
        //            }
        //        }
        //    }
        //}
        public void AddApplierToEmployer(Applier applier, int ad_id)
        {
            for (int i = 0; i < Employers.Count; i++)
            {
                for (int k = 0; k < Employers[i].Vacancies.Count; k++)
                {
                    if (Employers[i].Vacancies[k].Id == ad_id)
                    {
                        Employers[i].Vacancies[k].AddApplier(applier);
                    }
                }
            }
        }
        public Employer GetEmployerByAdID(int id)
        {
            for (int i = 0; i < Employers.Count; i++)
            {
                for (int k = 0; k < Employers[i].Vacancies.Count; k++)
                {
                    if (Employers[i].Vacancies[k].Id == id)
                    {
                        return Employers[i];
                    }
                }
            }
            return null;
        }
        public Employer GetEmployerByData(string username, string password)
        {
            for (int i = 0; i < Employers.Count; i++)
            {
                if (Employers[i].Username == username && Employers[i].Password == password)
                {
                    return Employers[i];
                }
            }
            return null;
        }

        public Worker GetWorkerByData(string username, string password)
        {
            for (int i = 0; i < Workers.Count; i++)
            {
                if (Workers[i].Username == username && Workers[i].Password == password)
                {
                    return Workers[i];
                }
            }
            return null;
        }

        public bool IsWorkerExist(string username, string password)
        {
            for (int i = 0; i < Workers.Count; i++)
            {
                if (Workers[i].Username == username && Workers[i].Password == password)
                {
                    return true;
                }
            }
            return false;
        }

        public bool IsEmployerExist(string username, string password)
        {
            for (int i = 0; i < Employers.Count; i++)
            {
                if (Employers[i].Username == username || Employers[i].Password == password)
                {
                    return true;
                }
            }
            return false;
        }

        public void ShowAllAds()
        {
            if (Employers.Count != 0)
            {
                for (int i = 0; i < Employers.Count; i++)
                {
                    Employers[i].ShowSimpleVacancies();
                }
            }
        }

        public Vacancy GetVacancyByID(int id)
        {

            for (int i = 0; i < Employers.Count; i++)
            {
                for (int k = 0; k < Employers[i].Vacancies.Count; k++)
                {
                    if (Employers[i].Vacancies[k].Id == id)
                    {
                        return Employers[i].Vacancies[k];
                    }
                }
            }

            return null;
        }

        public Applier GetApplierByID(int id)
        {
            for (int i = 0; i < Employers.Count; i++)
            {
                for (int k = 0; k < Employers[i].Vacancies.Count; k++)
                {
                    for (int j = 0; j < Employers[i].Vacancies[k].Appliers.Count; j++)
                    {
                        if (Employers[i].Vacancies[k].Appliers[j].Id == id)
                        {
                            return Employers[i].Vacancies[k].Appliers[j];
                        }
                    }
                }
            }
            return null;
        }
        public CV GetCVByID(int id)
        {
            for (int i = 0; i < Workers.Count; i++)
            {
                for (int k = 0; k < Workers[i].CVs.Count; k++)
                {
                    if (Workers[i].CVs[k].Id == id)
                    {
                        return Workers[i].CVs[k];
                    }
                }
            }
            return null;
        }

    }


    class Globals
    {
        public static string[] specialities = new string[10] {"Finance","Marketing","IT/Programming Field","Sale","Desing","Law",
        "Education/Schooling","Engineering","Service","Medical"};
        public static string[][] categories = new string[10][]
        {
            new string[8]{"Credit Specialist","Insurance","Audit","Accountant","Finance Analysis","Bank Service","Cashier","Economist"},
            new string[4]{ "Marketing Management", "Corporate Communications","Advertising","Corporating"},
            new string[6]{"System Management","Database Control","IT Specialist/Advisor","Programming","IT Project Management","Hardware Specialist"},
            new string[2]{"Real Estate Agent","Sale Specialist"},
            new string[3]{"Web Design","Artist","Fashion Design"},
            new string[3]{"Advocate","Law Advisor","Crime Investigation"},
            new string[4]{"Tutor","Language Specialist","Special Education","Schooling"},
            new string[4]{"Agriculture","Automated Machinery Control","Engineering","Construction"},
            new string[9]{"WarehouseMan","Janitor","Restaurant Job","Driver","BabySitter","Laboring","Translator","Courier","Security Agent"},
            new string[2]{"Doctor","Medical Advisor"}
        };

        public static Worker worker1 = new Worker()
        {
            Name = "Ali",
            Surname = "Ahmadov",
            Age = 20,
            City = "Baku",
            Phone = "050-311-72-66",
            Username = "user",
            Password = "user"
        };

        public static Worker worker2 = new Worker()
        {
            Name = "John",
            Surname = "Wick",
            Age = 20,
            City = "Sumqayit",
            Phone = "070-310-23-11",
            Username = "user1",
            Password = "user1"
        };

        public static Employer employer1 = new Employer()
        {
            Name = "John",
            Surname = "Wick",
            Age = 25,
            Phone = "050-432-45-32",
            City = "Baku",
            Username = "admin",
            Password = "admin",

        };


        public static CV worker1_CV = new CV()
        {
            School = "Zangi Liceum",
            Speciality = "Programmer",
            UniScore = "653",
            HasCertificate = true,
            BeginDate = new DateTime(2015, 1, 1),
            EndDate = new DateTime(2018, 5, 5)
        };

        public static Vacancy vacancy = new Vacancy()
        {
            AboutWork = $@"
    We are looking for an experienced Strategy Manager. You will work directly with C-suite level executives to ensure that daily objectives, reports, and metrics align directly with the company’s goals.

    Evaluate new business models and corporate relationships.
    Negotiate complex business models, partnerships, transactions, and other commercial agreements.
    Identify and target attainable opportunities in the market.
    Clearly define company goals and long-term strategy.
    Examine the profitability of each product, store location, and line of business in order to redirect resources.
    Utilize skills in project management to lead large teams in change processes.
    Develop methods for motivating and inspiring stakeholders.
    Leverage professional networks to attain critical resources.
    Provide training materials for process owners who need support.

",
            Requirements = $@"

    Experience in strategic planning and business analytics.
    Ability to lead, inspire and motivate teams.
    Strong presentation and negotiation skills.
    Excellent verbal and written communication in [X] language.
    [X] degree in Business Administration or relevant fields.
",
            City = "Baku",
            CompanyName = "Game Developer X",
            Education = "Bachelor, Master",
            Email = "aahmadov7626@ada.edu.az",
            MinAge = "20",
            MaxAge = "30",
            MinSalary = "2000",
            MaxSalary = "3500",
            Category = "Front End Developer",
            ExperienceDuration = "3",
            Phones = "050-311-11-11",
            Position = "Head Manager"

        };

        public static DataBase dataBase = new DataBase();

    }


    class Controller
    {
        public void Initialize()
        {
            Globals.worker1.AddCV(Globals.worker1_CV);
            Globals.worker1.CVs[0].AddLanguage("English");
            Globals.worker1.CVs[0].AddLanguage("Turkish");
            Globals.worker1.CVs[0].AddLanguage("Russian");
            Globals.worker1.CVs[0].AddLink($@"https://github.com/");
            Globals.worker1.CVs[0].AddSkill("C#, C++");



            Globals.employer1.AddVacancy(Globals.vacancy);

            Globals.dataBase.AddEmployer(Globals.employer1);
            Globals.dataBase.AddWorker(Globals.worker1);
            Globals.dataBase.AddWorker(Globals.worker2);


        }

        public void Start()
        {
            //Globals.worker1.ShowCVs();
            //Globals.employer1.ShowVacanciesDetailed();

           
            while (true)
            {
                Console.Clear();
                Helper.ShowMenu();
                Console.WriteLine("Enter your select: ");
                string select = Console.ReadLine();

                if (select == "1")
                {
                    //Admin
                    while (true)
                    {

                        Console.Clear();
                        Console.WriteLine("Enter username: ");
                        string username = Console.ReadLine();
                        Console.WriteLine("Enter password: ");
                        string password = Console.ReadLine();
                        Globals.dataBase = FileHelper.DeserializeDatabase(ref Globals.dataBase);
                        if (Globals.dataBase.IsEmployerExist(username, password))
                        {
                            var currentAdmin = Globals.dataBase.GetEmployerByData(username, password);
                            while (true)
                            {

                                Console.Clear();
                                Helper.ShowAdminMenu();
                                Console.WriteLine("Enter the option: ");
                                string admin_option = Console.ReadLine();

                                if (admin_option == "1")
                                {
                                    //Place new announcement
                                    Console.WriteLine("Enter email: ");
                                    string email = Console.ReadLine();
                                    Console.WriteLine("Enter the phone numbers: ");
                                    string phone = Console.ReadLine();
                                    Helper.ShowCategories(Globals.categories, Globals.specialities);
                                    Console.WriteLine("Choose category/Enter its name: ");
                                    string category = Console.ReadLine();
                                    Console.WriteLine("Enter the position: ");
                                    string position = Console.ReadLine();
                                    Console.WriteLine("Choose one city/Enter its name: ");
                                    string city = Console.ReadLine();
                                    Console.WriteLine("Min salary: ");
                                    string min_salary = Console.ReadLine();
                                    Console.WriteLine("Max salary: ");
                                    string max_salary = Console.ReadLine();
                                    Console.WriteLine("Min age: ");
                                    string min_age = Console.ReadLine();
                                    Console.WriteLine("Max age: ");
                                    string max_age = Console.ReadLine();
                                    Console.WriteLine("Education level: ");
                                    string education_level = Console.ReadLine();
                                    Console.WriteLine("Experience duration requirement: ");
                                    string ex_req = Console.ReadLine();
                                    Console.WriteLine("Requirements: ");
                                    string reqs = Console.ReadLine();
                                    Console.WriteLine("About Work/Description: ");
                                    string description = Console.ReadLine();
                                    Console.WriteLine("Company Name: ");
                                    string company_Name = Console.ReadLine();

                                    Vacancy new_vacancy = new Vacancy()
                                    {
                                        AboutWork = description,
                                        Category = category,
                                        City = city,
                                        Education = education_level,
                                        ExperienceDuration = ex_req,
                                        MinAge = min_age,
                                        MaxAge = max_age,
                                        MinSalary = min_salary,
                                        MaxSalary = max_salary,
                                        Email = email,
                                        Phones = phone,
                                        Position = position,
                                        CompanyName = company_Name,
                                        Requirements = reqs
                                    };

                                    currentAdmin.AddVacancy(new_vacancy);
                                    Console.ForegroundColor = ConsoleColor.Green; Console.WriteLine($"Dear {currentAdmin.Name}, new vacancy has been added successfully to your portfolio."); Console.ResetColor();
                                    Console.ReadKey();
                                    FileHelper.SerializeDatabase(Globals.dataBase);
                                }
                                else if (admin_option == "2")
                                {
                                    //Take a look at ads
                                    Console.Clear();
                                    currentAdmin.ShowVacanciesDetailed();
                                    Console.ReadKey();
                                }
                                else if (admin_option == "3")
                                {
                                    //Observe appliers
                                    Console.Clear();
                                    currentAdmin.ShowSimpleVacancies();
                                    Console.WriteLine("Enter ID: ");
                                    string id = Console.ReadLine();

                                    currentAdmin.ShowAppliers(Convert.ToInt32(id));
                                    var vacancy = Globals.dataBase.GetVacancyByID(Convert.ToInt32(id));

                                    if (vacancy.Appliers.Count != 0)
                                    {

                                        while (true)
                                        {
                                            Console.WriteLine("Enter applier ID for detailed view: ");
                                            string app_id = Console.ReadLine();
                                            var applier = Globals.dataBase.GetApplierByID(Convert.ToInt32(app_id));
                                            if (applier == null) throw new NotFoundApplierByIDException();
                                            Console.Clear();
                                            applier.ShowApplier();
                                            applier.Cv.Show();
                                            Console.WriteLine("For acceptance - 1\nFor rejection - 2\nGo Back - 0 : ");
                                            string selection = Console.ReadLine();
                                            if (selection == "1")
                                            {
                                                Console.ForegroundColor = ConsoleColor.Green; Console.WriteLine($"Applier ({applier.worker.Name}) with ID {applier.Id} has successfully been accepted"); Console.ResetColor();
                                                Notification notification = new Notification() { Message = $"Good News - You have been accepted for advertisement with ID {vacancy.Id} by employer {currentAdmin.Name} !!!" };
                                                Globals.dataBase.AddNotificationToWorker(notification, applier.worker.Id);
                                                Globals.dataBase.RemoveApplier(applier.Id);
                                                FileHelper.SerializeDatabase(Globals.dataBase);
                                            }
                                            else if (selection == "2")
                                            {
                                                Console.ForegroundColor = ConsoleColor.Red; Console.WriteLine($"Applier ({applier.worker.Name}) with ID {applier.Id} has successfully been rejected"); Console.ResetColor();
                                                Notification notification = new Notification() { Message = $"Sad News - You have been rejected for advertisement with ID {vacancy.Id} by employer {currentAdmin.Name} !!!" };
                                                Globals.dataBase.AddNotificationToWorker(notification, applier.worker.Id);
                                                Globals.dataBase.RemoveApplier(applier.Id);
                                                FileHelper.SerializeDatabase(Globals.dataBase);
                                            }
                                            else if (selection == "0") break;
                                            else
                                            {
                                                throw new WrongInputException();
                                            }
                                        }
                                    }
                                    Console.ReadKey();

                                }
                                else if (admin_option == "4")
                                {
                                    Console.Clear();
                                    currentAdmin.ShowNotifications();
                                    Console.ReadKey();
                                }
                                else if (admin_option == "0")
                                {
                                    break;
                                }
                                else
                                {
                                    throw new WrongInputException();
                                }

                            }
                        }
                        else
                        {
                            throw new UsernameOrPasswordWrong();
                        }
                    }
                }

                else if (select == "2")
                {
                    //User
                    while (true)
                    {
                        Console.Clear();
                        Console.WriteLine("Enter username: ");
                        string username = Console.ReadLine();
                        Console.WriteLine("Enter password: ");
                        string password = Console.ReadLine();

                        var currentUser = Globals.dataBase.GetWorkerByData(username, password);
                        if (username == "" || password == "") break;
                        if (currentUser != null)
                        {
                            while (true)
                            {
                                Console.Clear();
                                Helper.ShowUserMenu();
                                Console.WriteLine("Enter the option: ");
                                string user_option = Console.ReadLine();

                                if (user_option == "1")
                                {
                                    //Show Ads
                                    Console.Clear();
                                    Globals.dataBase.ShowAllAds();
                                    // Console.ReadKey();

                                    Console.WriteLine("Look detailed by Vacancy ID(Enter ID / Go back 0): ");
                                    string vacancy_id = Console.ReadLine();
                                    if (vacancy_id == "0") break;
                                    bool hasParsed = int.TryParse(vacancy_id, out int result);
                                    if (hasParsed)
                                    {
                                        var vacancy = Globals.dataBase.GetVacancyByID(result);

                                        if (vacancy != null)
                                        {
                                            Console.Clear();
                                            vacancy.ShowVacancyDetailed();
                                            Console.ReadKey();
                                        }
                                        else
                                        {
                                            throw new NotFoundVacancyByIDException();
                                        }
                                    }
                                    else
                                    {
                                        throw new SystemCorruptionException();
                                    }

                                }
                                else if (user_option == "2")
                                {
                                    //Bid any ad

                                    Console.Clear();
                                    Globals.dataBase.ShowAllAds();

                                    Console.WriteLine("Enter ID: ");
                                    string ad_id = Console.ReadLine();
                                    bool hasParsed = int.TryParse(ad_id, out int result);
                                    if (hasParsed)
                                    {
                                        var ad = Globals.dataBase.GetVacancyByID(result);
                                        if (ad != null)
                                        {
                                            Console.Clear();
                                            currentUser.ShowCVs();
                                            CV worker_CV = new CV();
                                            Console.WriteLine("Which CV ? Enter ID: ");
                                            string id = Console.ReadLine();
                                            bool IdParsed = int.TryParse(id, out int id_result);
                                            if (IdParsed)
                                            {
                                                var Cv = Globals.dataBase.GetCVByID(id_result);
                                                if (Cv == null) throw new NotFoundCVByIDException();
                                                worker_CV = Cv;
                                            }
                                            else throw new SystemCorruptionException();

                                            Applier applier = new Applier() { worker = currentUser, Cv = worker_CV };

                                            
                                            Globals.dataBase.AddApplierToEmployer(applier, Convert.ToInt32(ad_id));

                                            Console.ForegroundColor = ConsoleColor.Green;
                                            Console.WriteLine($"Successfully applied to ad with ID {ad.Id}");
                                            Console.ResetColor();
                                            Console.ReadKey();

                                            Notification notification = new Notification() { Message = $"{currentUser.Name} with ID {currentUser.Id} has applied to your add with ID {ad_id}" };
                                            Globals.dataBase.AddNotificationToEmployer(notification, Convert.ToInt32(ad_id));
                                            FileHelper.SerializeDatabase(Globals.dataBase);
                                        }
                                        else
                                        {
                                            throw new NotFoundVacancyByIDException();
                                        }
                                    }
                                    else
                                    {
                                        throw new SystemCorruptionException();
                                    }

                                }
                                else if (user_option == "3")
                                {
                                    //Show CVs
                                    currentUser.ShowCVs();
                                    Console.ReadKey();
                                }
                                else if (user_option == "4")
                                {
                                    //Create new CV
                                    CV newCV = new CV();
                                    Console.WriteLine("Enter speciality : ");
                                    string speciality = Console.ReadLine();
                                    Console.WriteLine("Enter school : ");
                                    string school = Console.ReadLine();
                                    Console.WriteLine("Enter university score: ");
                                    string score = Console.ReadLine();

                                    while (true)
                                    {
                                        Console.Clear();
                                        Console.WriteLine("Enter language and proficiency level / Enter 0 if you done: ");
                                        string language = Console.ReadLine();
                                        if (language == "0") break;
                                        newCV.AddLanguage(language);
                                    }
                                    while (true)
                                    {
                                        Console.Clear();
                                        Console.WriteLine("Enter companies you cooperated with / Enter 0 if you done: ");
                                        string company = Console.ReadLine();
                                        if (company == "0") break;
                                        newCV.AddCompany(company);
                                    }

                                    while (true)
                                    {
                                        Console.Clear();
                                        Console.WriteLine("Enter skills / Enter 0 if you done: ");
                                        string skill = Console.ReadLine();
                                        if (skill == "0") break;
                                        newCV.AddSkill(skill);
                                    }

                                    while (true)
                                    {
                                        Console.Clear();
                                        Console.WriteLine("Enter links / Enter 0 if you done: ");
                                        string link = Console.ReadLine();
                                        if (link == "0") break;
                                        newCV.AddLink(link);
                                    }
                                    Console.Clear();
                                    Console.WriteLine("Enter start working day / month / year : ");
                                    string day = Console.ReadLine();
                                    string month = Console.ReadLine();
                                    string year = Console.ReadLine();

                                    Console.WriteLine("Enter end working day / month / year : ");
                                    string day1 = Console.ReadLine();
                                    string month1 = Console.ReadLine();
                                    string year1 = Console.ReadLine();

                                    DateTime dateTime_start = new DateTime(Convert.ToInt32(year), Convert.ToInt32(month), Convert.ToInt32(day));
                                    DateTime dateTime_end = new DateTime(Convert.ToInt32(year1), Convert.ToInt32(month1), Convert.ToInt32(day1));

                                    newCV.BeginDate = dateTime_start;
                                    newCV.EndDate = dateTime_end; newCV.School = school; newCV.UniScore = score; newCV.Speciality = speciality;
                                    currentUser.AddCV(newCV);
                                    Console.WriteLine();
                                    Console.ForegroundColor = ConsoleColor.Green; Console.WriteLine("CV has been successfully created !!!"); Console.ResetColor();
                                    Console.ReadKey();

                                }
                                else if (user_option == "5")
                                {
                                    Console.Clear();
                                    currentUser.ShowNotifications();
                                    Console.ReadKey();
                                }
                                else if (user_option == "0")
                                {
                                    break;
                                }
                                else
                                {
                                    throw new WrongInputException();
                                }
                            }
                        }
                        else
                        {
                            throw new UsernameOrPasswordWrong();
                        }
                    }
                }
                else
                {
                    throw new WrongInputException();
                }
            }
        }
    }

    public class Program
    {
        static void Main(string[] args)
        {
            Controller controller = new Controller();
            controller.Initialize();
            FileHelper.SerializeDatabase(Globals.dataBase);
            while (true)
            {
                try
                {
                    controller.Start();
                }
                catch (Exception ex)
                {
                    Console.WriteLine(ex.Message);
                    Console.ReadKey();
                    Console.Clear();
                    continue;
                }
            }
        }
    }
}
