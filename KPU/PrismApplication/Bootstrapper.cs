using System.Windows;
using Microsoft.Practices.Prism.Modularity;
using Microsoft.Practices.Prism.UnityExtensions;
using Microsoft.Practices.Unity;

namespace PrismApplication
{
    class Bootstrapper : UnityBootstrapper
    {
        private ModuleCatalog _moduleCatalog;

        protected override DependencyObject CreateShell()
        {
            return new Shell();
        }

        protected override void InitializeShell()
        {
            base.InitializeShell();

            Application.Current.MainWindow = (Window)this.Shell;
            Application.Current.MainWindow.Show();
        }

        protected override void ConfigureModuleCatalog()
        {
            base.ConfigureModuleCatalog();
            _moduleCatalog = (ModuleCatalog)this.ModuleCatalog;
            _moduleCatalog.AddModule(typeof(PrismModules.MainModule));
            _moduleCatalog.AddModule(typeof(PrismModules.MenuModule));
            _moduleCatalog.AddModule(typeof(PrismModules.LogModule));
            _moduleCatalog.AddModule(typeof(PrismModules.StatusModule));
        }
    }
}
