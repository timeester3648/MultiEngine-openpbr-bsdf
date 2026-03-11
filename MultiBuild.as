void main(MultiBuild::Workspace& workspace) {	
	auto project = workspace.create_project(".");
	auto properties = project.properties();

	project.name("openpbr-bsdf");
	properties.binary_object_kind(MultiBuild::BinaryObjectKind::eUtility);
	project.license("./LICENSE");
	properties.tags("use_header_only_mle");

	project.include_own_required_includes(true);
	project.add_required_project_include({
		".",
		"./mle-interop"
	});

	properties.files({
		"./**.h",
		"./**.hpp"
	});

	properties.pre_build_commands("{:copy_directory:} \"{:project.root}/impl\" \"{:workspace.root}/resources/shaders/MultiEngine/vendor/adobe/openpbr/impl/impl\"");
	properties.pre_build_commands("{:copy_directory:} \"{:project.root}/interop\" \"{:workspace.root}/resources/shaders/MultiEngine/vendor/adobe/openpbr/impl/interop\"");

	{
		MultiBuild::ScopedFilter _(project, "config.platform:Windows");
		properties.pre_build_commands("{:copy_file:} \"{:project.root}/*.h\" \"{:workspace.root}/resources/shaders/MultiEngine/vendor/adobe/openpbr/impl\"");
	}

	{
		MultiBuild::ScopedFilter _(project, "!config.platform:Windows");
		// Note: linux does not support wildcard in quoted path
		properties.pre_build_commands("{:copy_file:} \"{:project.root}\"/*.h \"{:workspace.root}/resources/shaders/MultiEngine/vendor/adobe/openpbr/impl\"");
	}
}