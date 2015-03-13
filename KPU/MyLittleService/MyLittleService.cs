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
        private string _sourcePath;
        private string _targetPath;

        private delegate void WatcherDelegate(string sourcePath);

        private WatcherDelegate Wd;
        public FileWatcher(string sourcePath, string targetPath)
        {
            _sourcePath = sourcePath;
            _targetPath = targetPath;
            Wd = new WatcherDelegate(TurnOnWatch);

            if (!Directory.Exists(_sourcePath) || !Directory.Exists(_targetPath))
            {
                return;
            }
        }

        public void StartToWatch()
        {
            Wd.BeginInvoke(_sourcePath, null,null);
        }
        private void TurnOnWatch(string sourcePath)
        {
            var watcher = new FileSystemWatcher(sourcePath);

            watcher.Changed += new FileSystemEventHandler(EventHandler);
        }

        public void EventHandler(object source, FileSystemEventArgs e)
        {
            if (e.ChangeType != WatcherChangeTypes.Changed)
            {
                return;
            }
            FileStream fsSource = new FileStream(e.FullPath, FileMode.Open, FileAccess.Read);
            FileStream fsTarget = new FileStream(_targetPath, FileMode.Append, FileAccess.ReadWrite);

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
            FileWatcher fileWatcher = new FileWatcher(@"C:\tmp", @"C:\targetTmp\tmp.txt");
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
