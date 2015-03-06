using Microsoft.Practices.Prism.Modularity;
using Microsoft.Practices.Prism.Regions;


namespace HelloWorldModule
{
    public class HelloWorldModule : IModule
    {
        private readonly IRegionManager _regionManager;

        public HelloWorldModule(IRegionManager regionManager)
        {
            _regionManager = regionManager;
        }

        public void Initialize()
        {
            _regionManager.RegisterViewWithRegion("MainRegion", typeof (Views.HelloWorldView));
        }
    }
}
