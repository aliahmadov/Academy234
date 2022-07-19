using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Boss.AZ_Project_CSharp
{
    class FileHelper
    {

        static public void SerializeDatabase(DataBase dataBase)
        {
            var serializer = new JsonSerializer();
            using (var sw = new StreamWriter("database.json"))
            {
                using (var jw = new JsonTextWriter(sw))
                {
                    jw.Formatting = Formatting.Indented;
                    serializer.Serialize(jw, dataBase);
                }
            }

        }

        public static DataBase DeserializeDatabase(ref DataBase dataBase)
        {
            var serializer = new JsonSerializer();

            using (var sr = new StreamReader("database.json"))
            {
                using (var jr = new JsonTextReader(sr))
                {
                    return serializer.Deserialize<DataBase>(jr);
                }
            }

        }
    }
}
