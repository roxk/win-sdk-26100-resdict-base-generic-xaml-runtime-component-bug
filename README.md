# Minimal Repro for a bug for runtime component in Windows SDK 26100

# Fixed as of may 2026: https://discord.com/channels/372137812037730304/580484470877061120/1508126214802378873

## Pre-requisites
1. Visual Studio 2022
	- UWP C++ workload
	- Windows SDK 26100
	- Windows SDK 22621 (or other lower versions)

## Steps to Reproduce
1. Build the project (default SDK is 26100)
2. Observe the following error in Output window:
```
1>  Validating metadata file x64\Debug\Merged\RuntimeComponent2.winmd.
1>  pch.cpp
1>  module.g.cpp
1>  Template.cpp
1>  XamlTypeInfo.Impl.g.cpp
1>  XamlLibMetadataProvider.g.cpp
1>C:\Program Files (x86)\Windows Kits\10\bin\10.0.26100.0\XamlCompiler\Microsoft.Windows.UI.Xaml.Common.targets(456,5): Xaml Internal Error error WMC9999: Value cannot be null.
1>C:\Program Files (x86)\Windows Kits\10\bin\10.0.26100.0\XamlCompiler\Microsoft.Windows.UI.Xaml.Common.targets(456,5): Xaml Internal Error error WMC9999: Parameter name: name
```
3. Change SDK to 22621 (in GUI, or edit project file -> toggle version comment)
4. Observe the project builds successfully

## Notes

This project is created by:
1. Create a blank C++ UWP runtime component
2. Remove default Class.idl
3. Add a new XAML page with name `Template`. Change the base type from `Page` to `ResourceDictionary` in xaml and idl. Remove all properties/methods (leave constructor in idl).
4. Add a new resource dictionary with path `Themes/Generic.xaml`
