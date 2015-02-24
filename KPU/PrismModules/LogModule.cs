using Microsoft.Practices.Prism.Modularity;
using Microsoft.Practices.Prism.Regions;

namespace PrismModules
{
    public class LogModule : IModule
    {
        private readonly IRegionManager _regionManager;

        public LogModule(IRegionManager regionManager)
        {
            _regionManager = regionManager;
        }

        public void Initialize()
        {
            _regionManager.RegisterViewWithRegion("LogRegion", typeof(Views.LogView));
        }
    }
}
