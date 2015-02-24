using Microsoft.Practices.Prism.Modularity;
using Microsoft.Practices.Prism.Regions;

namespace PrismModules
{
    public class StatusModule :IModule
    {
        private readonly IRegionManager _regionManager;

        public StatusModule(IRegionManager regionManager)
        {
            _regionManager = regionManager;
        }

        public void Initialize()
        {
            _regionManager.RegisterViewWithRegion("StatusRegion", typeof (Views.StatusView));
        }
    }
}
