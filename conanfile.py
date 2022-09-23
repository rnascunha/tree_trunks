from conans import ConanFile

class TreeTrunksConan(ConanFile):
    name = "tree_trunks"
    version = "0.1"
    # No settings/options are necessary, this is header only
    exports_sources = "include/*", "CMakeLists.txt"
    exports = "LICENSE"
    no_copy_source = True

    def package(self):
        self.copy("*.hpp")
