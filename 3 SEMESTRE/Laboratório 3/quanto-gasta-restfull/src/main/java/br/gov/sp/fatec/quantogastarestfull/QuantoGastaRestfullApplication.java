package br.gov.sp.fatec.quantogastarestfull;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.boot.builder.SpringApplicationBuilder;
import org.springframework.boot.web.servlet.support.SpringBootServletInitializer;

@SpringBootApplication
public class QuantoGastaRestfullApplication extends SpringBootServletInitializer {

	public static void main(String[] args) {
		SpringApplication.run(QuantoGastaRestfullApplication.class, args);
	}

	@Override
	protected SpringApplicationBuilder configure(SpringApplicationBuilder application) {
		return application.sources(QuantoGastaRestfullApplication.class);
	}
}
