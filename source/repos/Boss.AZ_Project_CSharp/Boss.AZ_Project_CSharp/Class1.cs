using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Boss.AZ_Project_CSharp
{
    public class WrongInputException : ApplicationException
    {

        public override string Message => $"Your input has not been identified by our system, Try again ...";
    }

    public class SystemCorruptionException : ApplicationException
    {
        public override string Message => $"System has been corrupted for a particular reason\nPlease start your operation again ...";
    }

    public class UsernameOrPasswordWrong : ApplicationException
    {
        public override string Message => $"Username or password has been entered incorrectly, try again ...";
    }

    public class NotFoundByEnteredIDException : ApplicationException
    {
        public override string Message => $"The data you are looking for with entered ID do not exist in this context\nTry Again...";
    }

    public class NotFoundVacancyByIDException : ApplicationException
    {
        public override string Message => "The vacancy with your input ID has not been found in our database !!!";
    }

    public class NotFoundCVByIDException : ApplicationException
    {
        public override string Message => "The CV with your input ID has not been found in our database !!!";
    }

    public class NotFoundApplierByIDException : ApplicationException
    {
        public override string Message => "The Applier with your input ID has not been found in our database !!!";
    }
    class Helper
    {
        public static void ShowMenu()
        {
            Console.WriteLine("A D M I N    1");
            Console.WriteLine("U S E R      2");
        }

        public static void ShowAdminMenu()
        {
            Console.WriteLine("Place a new announcement      1");
            Console.WriteLine("Take a look at ads            2");
            Console.WriteLine("Observe appliers              3");
            Console.WriteLine("Look at Notifications         4");
        }

        public static void ShowUserMenu()
        {
            Console.WriteLine("Show Work Announcements         1");
            Console.WriteLine("Bid Add                         2");
            Console.WriteLine("Show CVs                        3");
            Console.WriteLine("Create new CV                   4");
            Console.WriteLine("Look at Notifications           5");
        }

        public static void ShowCategories(string[][] strings, string[]strings_2)
        {
            Console.WriteLine();
            for (int i = 0; i < strings.Length; i++)
            {
                Console.ForegroundColor = ConsoleColor.Red;  Console.WriteLine(strings_2[i]);Console.ResetColor();
                for (int k = 0; k < strings[i].Length; k++)
                {
                    Console.WriteLine(strings[i][k]);
                }
                Console.WriteLine();
            }
        }
    }


}
