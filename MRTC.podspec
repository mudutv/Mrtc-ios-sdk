Pod::Spec.new do |s|
  s.name = "MRTC"
  s.version = "1.0.8"
  s.summary = "A stream SDK of MuDu"
  s.license = {"type"=>"MIT", "file"=>"LICENSE"}
  s.authors = {"张志超"=>"zhangzhichao@mudu.tv"}
  s.homepage = "https://mudu.tv"
  s.description = "TODO: Add long description of the pod here."
  s.source = { :git => 'https://git.mudu.tv/myun/mrtc-framework.git', :tag => s.version.to_s }

  s.ios.deployment_target    = '9.0'
  s.ios.vendored_framework   = 'ios/MRTC.framework'
  # s.frameworks = 'AVFundation','UIKit','CoreMedia'
  s.frameworks = 'CoreMedia','AVFoundation'
  s.dependency 'GoogleWebRTC','1.1.27121'
  s.pod_target_xcconfig = {
      'ENABLE_BITCODE' => 'NO',
      'VALID_ARCHS' => 'arm64 arm64e armv7s',
      'OTHER_LDFLAGS' => '-lObjC'
  }
end
