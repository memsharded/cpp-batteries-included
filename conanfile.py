from conans import ConanFile, CMake


class Test(ConanFile):
    settings = "os", "compiler", "arch", "build_type"
    requires = ("rang/3.1.0@rang/stable",
                "Expat/2.2.4@pix4d/stable",
                "fmt/4.1.0@bincrafters/stable",
                "boost/1.66.0@conan/stable",
                "Poco/1.8.1@pocoproject/stable",
                "cereal/1.2.2@conan/stable",
                "cli11/1.3.0@bincrafters/stable",
                "functionalplus/v0.2-p1@dobiasd/stable",
                "glog/0.3.5@bincrafters/stable"
    )
    generators = "cmake"

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()