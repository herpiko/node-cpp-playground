{
  "targets": [
    {
      "target_name": "filebin",
      "sources": [ "filebin.cpp" ],
      "include_dirs": [],
      "libraries": [],
      "cflags_cc": [ "-std=c++11 -lstdc++"],
      "cflags": [ "-std=c++11 -lstdc++" ],
      "ldflags": [],
      "conditions": [
        ["OS!='win'", {
          "defines": [],
          "link_settings": {
            "libraries": [ "-L<(module_root_dir)/build" ],
            "library_dirs": []
          }
        }]
      ]
    }
  ]
}

