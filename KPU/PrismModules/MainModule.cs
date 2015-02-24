using Microsoft.Practices.Prism.Modularity;
using Microsoft.Practices.Prism.Regions;

namespace PrismModules
{
    public class MainModule : IModule
    {
        private readonly IRegionManager _regionManager;

        public MainModule(IRegionManager regionManager)
        {
            _regionManager = regionManager;
        }


        public void Initialize()
        {
            _regionManager.RegisterViewWithRegion("MainRegion", typeof (Views.MainView));
        }
    }
}
