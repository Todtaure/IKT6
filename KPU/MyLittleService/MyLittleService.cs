using System;
using System.CodeDom;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Runtime.CompilerServices;
using System.ServiceProcess;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace MyLittleService
{
    public class FileWatcher
    {
        private readonly string _sourcePath;
        private readonly string _targetPath;

        private delegate void WatcherDelegate(string sourcePath);

        private WatcherDelegate Wd;
        public FileWatcher(string sourcePath, string targetPath)
        {
            _sourcePath = sourcePath;
            _targetPath = targetPath;
            Wd = new WatcherDelegate(TurnOnWatch);

            if (!Directory.Exists(_sourcePath) || !File.Exists(_targetPath))
            {
                return;
            }

            StartToWatch();
        }

        public void StartToWatch()
        {
            Wd.BeginInvoke(_sourcePath, null, null);
        }
        private void TurnOnWatch(string sourcePath)
        {
            var watcher = new FileSystemWatcher(sourcePath);

            watcher.Filter = "*.txt";
            watcher.NotifyFilter = NotifyFilters.LastAccess | NotifyFilters.LastWrite | NotifyFilters.FileName;
            //watcher.Changed += EventHandler;
            watcher.Created += EventHandler;

            watcher.EnableRaisingEvents = true;
        }

        public void EventHandler(object source, FileSystemEventArgs e)
        {
            FileStream fsSource = new FileStream(e.FullPath, FileMode.Open, FileAccess.Read);
            FileStream fsTarget = new FileStream(_targetPath, FileMode.Append, FileAccess.Write);

            try
            {
                fsSource.CopyTo(fsTarget);

            }
            finally
            {
                fsTarget.Close();
                fsSource.Close();
            }
        }
    }

    public partial class MyLittleService : ServiceBase
    {
        public MyLittleService()
        {
            this.AutoLog = false;
            InitializeComponent();
            eventLog1 = new System.Diagnostics.EventLog();
            if (!System.Diagnostics.EventLog.SourceExists("MySource"))
            {
                System.Diagnostics.EventLog.CreateEventSource(
                    "MySource", "MyNewLog");
            }
            eventLog1.Source = "MySource";
            eventLog1.Log = "MyNewLog";
        }

        protected override void OnStart(string[] args)
        {
            eventLog1.WriteEntry("In OnStart");
            FileWatcher fileWatcher = new FileWatcher(@"C:\tmpSource", @"C:\tmpTarget\tmp.txt");
        }

        protected override void OnStop()
        {
            eventLog1.WriteEntry("In onStop.");
        }

        protected override void OnContinue()
        {
            eventLog1.WriteEntry("In OnContinue.");
        }
    }
}
