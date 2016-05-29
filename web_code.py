import web

urls = (
    '/', 'Index',
    '/favicon.ico','Icon',
)

class Index:
    def GET(self):
        return "Hello, world!"

class Icon:
	def GET(self):
		raise web.seeother("./static/favicon.ico")

if __name__ == "__main__":
    app = web.application(urls, globals())
    app.run()
